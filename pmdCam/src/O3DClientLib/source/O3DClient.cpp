/* 
 * File:   O3DClient.cpp
 * Author: Maciek
 * 
 * Created on 13 maj 2010, 22:37
 */

#include "../include/O3DClient.hpp"

#include "../include/communication/structs.h"
#include "../include/communication/clientsocket.h"
#include "../include/communication/CPcomm3dErrors.h"
#include "../include/o3dCompleteData.hpp"
#include "../include/o3dCameraSettings.hpp"

//#include "../include/xml_rpc/XmlRpc.h"
#include <ros/ros.h>
#include "XmlRpc.h"
/*
#include "XmlRpcClient.h"
#include "XmlRpcException.h"
#include "XmlRpcServer.h"
#include "XmlRpcServerMethod.h"
#include "XmlRpcValue.h"
#include "XmlRpcUtil.h"
*/

#include <cstdio>
#include <iostream>
#include <ctime>
#include <sys/timeb.h>
#include <cassert>

#ifdef O3D_USE_BOOST
#include <boost/date_time.hpp>
#endif

namespace o3d{

struct o3dDataHeader{
    o3dDataType type;
    T_IMAGEHEADER header;
    float *pf_finalImageBuffer;
    unsigned long int OldImageTimeStamp;

    o3dDataHeader(float *finalImageBuffer)
    : pf_finalImageBuffer(finalImageBuffer)
    {
        OldImageTimeStamp = 0;
    }

    ~o3dDataHeader(){
    }

    void saveToFile(std::string filename);
    void readFromFile(std::string filename);
};


o3dClient::o3dClient()
{
#ifdef O3D_USE_BOOST
    _read_thread = 0;
    _stop_thread = true;
#endif

    _connected = false;

    pf_ImageBuffer = new float[IMG_HEIGHT*IMG_WIDTH+sizeof(T_IMAGEHEADER)/sizeof(float)];

    pXmlClient = 0;
    pImageServerClientSocket = 0;
    
//    desSamplingRate      = 0;
//    ui_TCPPort     = 50002;
    reconnectCount=0;
//    str_IP    = "192.168.0.69"; //Adres fabryczny
//    i_xmlport = 8080; //Port fabryczny
//    res = 0;
//    triggerMode    = 4; //SW
//    iEnableMedianFilter = 0;
//    iEnableMeanValueFilter = 0;

//    _frontend_data = new T_FrontendData();
//    _frontend_data->i_modulationFrequency  = 0;
//    _frontend_data->i_illuMode             = 0;
//    _frontend_data->i_resetDuration        = 20;
//    _frontend_data->i_samplingMode = 0; //Single
//    _frontend_data->i_integrationTimeSingle = 125;
//    _frontend_data->i_integrationTimeDouble = 2000;
//    _frontend_data->i_ifmTime      = 100;
    
    _camera_settings = new o3dCameraSettings();

    _image_data = new o3dCompleteData();

    _image_data_headers[dtype_i] = new o3dDataHeader(&_image_data->data_i[0]);
    _image_data_headers[dtype_d] = new o3dDataHeader(&_image_data->data_d[0]);
    _image_data_headers[dtype_x] = new o3dDataHeader(&_image_data->data_x[0]);
    _image_data_headers[dtype_y] = new o3dDataHeader(&_image_data->data_y[0]);
    _image_data_headers[dtype_z] = new o3dDataHeader(&_image_data->data_z[0]);
    _image_data_headers[dtype_e] = new o3dDataHeader(&_image_data->data_e[0]);
    _image_data_headers[dtype_f] = new o3dDataHeader(&_image_data->data_f[0]);
    _image_data_headers[dtype_g] = new o3dDataHeader(&_image_data->data_g[0]);
    _image_data_headers[dtype_s] = new o3dDataHeader(&_image_data->data_s[0]);

    setDataTypes("idxyzefgs");
}

o3dClient::~o3dClient()
{
#ifdef O3D_USE_BOOST
    stopReadThread();
#endif

    if (pf_ImageBuffer != 0)
    {
            delete[] pf_ImageBuffer;
            pf_ImageBuffer = 0;
    }

    delete _image_data_headers[dtype_i];
    delete _image_data_headers[dtype_d];
    delete _image_data_headers[dtype_x];
    delete _image_data_headers[dtype_y];
    delete _image_data_headers[dtype_z];
    delete _image_data_headers[dtype_e];
    delete _image_data_headers[dtype_f];
    delete _image_data_headers[dtype_g];
    delete _image_data_headers[dtype_s];

    delete _camera_settings;
    delete _image_data;
}

bool o3dClient::connected()
{
    return _connected;
}

/*!
* Connect to the sensor
*/
int o3dClient::Connect(std::string pIP,  unsigned int iXMLPort)
{
	char str_FWversion[255], str_SensorType[255];
	
	// Restart: delete the old object and create a new one
	if (pXmlClient != 0)
	{
		pXmlClient->close();
		delete pXmlClient;
		pXmlClient = 0;
	}

	pXmlClient = new XmlRpc::XmlRpcClient(pIP.c_str(), iXMLPort);

	XmlRpc::setVerbosity(0);

	if (pXmlClient == 0)
		return CPCOMM3D_ERR_NO_MEM;

	if (0 != readOwnIP(OwnIpAddress))
	{
		return -1;
	}
	XmlRpc::XmlRpcValue args, result;
	args[0] = OwnIpAddress;
	result [0] = -1;
	if( 4 == _camera_settings->getTriggerMode())
	{
		args[1] = 0; /* Turn Heartbeat off != 0 / Turn Heartbeat on == 0 */
	}
	else
	{
		args[1] = 1; /* Turn Heartbeat off != 0 / Turn Heartbeat on == 0 */
	}


	if (!pXmlClient->execute("MDAXMLConnectCP", args, result))
	{
		return CPCOMM3D_NO_CONNECTION;
	}

	if ((int) result[0] == CPCOMM3D_NO_ERRORS)
	{
		std::string str;

		str = static_cast<std::string>(result[1]);
		strcpy(&str_FWversion[0], str.c_str());
		str = static_cast<std::string>(result[2]);
		strcpy(&str_SensorType[0], str.c_str());

                _connected = true;
	}
	return result[0];
}

/*!
* Disconnect from the sensor
*/
int  o3dClient::Disconnect()
{
        _connected = false;

	XmlRpc::XmlRpcValue args, result;
	if (pXmlClient != 0)
	{
		args[0] = OwnIpAddress;
		result [0] = -1;

                bool ok = false;

                try
		{

                    ok = pXmlClient->execute("MDAXMLDisconnectCP", args, result);

                    pXmlClient->close();

                }
                catch (SocketClosedException e)
		{
//			std::cout << e.description() << endl;
			return CPCOMM3D_SOCKET_LIVE_IMAGE;
		}
		catch (SocketException e)
		{
//			std::cout << e.description() << endl;
			return CPCOMM3D_GETTING_LIVE_IMAGE;
		}

		delete pXmlClient;
                pXmlClient = 0;
                
                if (!ok)
		{
			return CPCOMM3D_NO_CONNECTION;
		}
		
	}	
	return result[0];
}
/*!
* Start the live image server
*/
int  o3dClient::StartLiveImageServer(int i_Port, std::string pIP)
{
	if (pImageServerClientSocket == 0)
	{
			pImageServerClientSocket = new ClientSocket(pIP.c_str(), i_Port);
			if (!pImageServerClientSocket->isOK())
				return CPCOMM3D_NO_CONNECTION;
	}
	return CPCOMM3D_NO_ERRORS;
}

/*!
* Stop the live image server
*/
int  o3dClient::StopLiveImageServer()
{
	char command[1];

	if (pImageServerClientSocket != 0)
	{
		command[0] = 'q';
		try
		{
			pImageServerClientSocket->sendData(sizeof(command), command);
			Sleep(1000);
		}
		catch (SocketClosedException e)
		{
//			std::cout << e.description() << endl;
			return CPCOMM3D_SOCKET_LIVE_IMAGE;
		}
		catch (SocketException e)
		{
//			std::cout << e.description() << endl;
			return CPCOMM3D_GETTING_LIVE_IMAGE;
		}

                delete pImageServerClientSocket;
                pImageServerClientSocket = 0;

		if (pXmlClient == 0)
		{
			return CPCOMM3D_COMM_NOT_WORKING;
		}

		
	}
	return CPCOMM3D_NO_ERRORS;
}
/*!
* Transmit the frontend data to the sensor
*/
int  o3dClient::SetFrontendData(T_FrontendData *p_FrontendData)
{
	if (pXmlClient == 0)
		return CPCOMM3D_COMM_NOT_WORKING;

	XmlRpc::XmlRpcValue args, result;
	result[0] = -1;

	args[0] = (int) 0; /* dummy */
	/* 0(23MHz)   1(20.4MHz)   2(20.6MHz) */
	args[1] = (int)(0);
	/* 0(Einfachbelichtung)   1(Doppelbelichtung) */
	args[2] = (int)(p_FrontendData->i_samplingMode);
	/*  immer 1 */
	args[3] = (int)(1);
	/* [1...5000] (�s)   EXP1<EXP2 */
	args[4] = (int)(p_FrontendData->i_integrationTimeDouble);
	/* [1...5000] (�s) */
	args[5] = (int)(p_FrontendData->i_integrationTimeSingle);
	/*  immer 20 */
	args[6] = (int)(20);
	/*  [1...10000] (ms)  die Pausendauer zwischen Ende der
	letzten und Anfang der n�chsten Bildaufnahme.
	Dauer der Bildaufnahme je nach Modus im Header.
	*/
	args[7] = (int)(p_FrontendData->i_ifmTime);
	args[8] = (int)(0);

	if (!pXmlClient->execute("MDAXMLSetFrontendData", args, result))
	{
		return CPCOMM3D_NO_CONNECTION;
	}
	p_FrontendData->i_modulationFrequency	= (int)(result[2]);
	p_FrontendData->i_samplingMode		= (int)(result[3]);
	p_FrontendData->i_illuMode		= (int)(result[4]);
	p_FrontendData->i_integrationTimeDouble	= (int)(result[5]);
	p_FrontendData->i_integrationTimeSingle	= (int)(result[6]);
	p_FrontendData->i_resetDuration		= (int)(result[7]);
	p_FrontendData->i_ifmTime		= (int)(result[8]);
	return result[0];
}

/*!
* Transmit the frontend data to the sensor
*/
int  o3dClient::GetFrontendData(T_FrontendData *p_FrontendData)
{
	if (pXmlClient == 0)
		return CPCOMM3D_COMM_NOT_WORKING;

	XmlRpc::XmlRpcValue args, result;
	result[0] = -1;
	if(!pXmlClient->execute ("MDAXMLGetFrontendData", args, result))
	{
		if (pXmlClient != 0)
		{
			pXmlClient->close ();
			delete pXmlClient;
			pXmlClient = 0;
		}
		return CPCOMM3D_NO_CONNECTION;
	}

	p_FrontendData->i_modulationFrequency	= (int)(result[2]);
	p_FrontendData->i_samplingMode		= (int)(result[3]);
	p_FrontendData->i_illuMode		= (int)(result[4]);
	p_FrontendData->i_integrationTimeSingle = (int)(result[5]);
	p_FrontendData->i_integrationTimeDouble = (int)(result[6]);
	p_FrontendData->i_resetDuration		= (int)(result[7]);
	p_FrontendData->i_ifmTime		= (int)(result[8]);

	return result[0];
}

/*!
* Sets the trigger mode
*/
int o3dClient::SetTrigger(int Mode)
{
	if (pXmlClient == 0)
		return CPCOMM3D_COMM_NOT_WORKING;

	XmlRpc::XmlRpcValue args, result;
	result[0] = -1;

	args[0] = (int)0;
	args[1] = (int)(0);
	args[2] = (int)(Mode);

	if (!pXmlClient->execute("MDAXMLSetTrigger", args, result))
	{
		return CPCOMM3D_NO_CONNECTION;
	}
//	cout << "TriggerMode " << Mode << endl;
	return result[0];
}

/*!
* Get the TCP-Data port number
*/
int o3dClient::GetTCPPort()
{
	if (pXmlClient == 0)
		return CPCOMM3D_COMM_NOT_WORKING;

	XmlRpc::XmlRpcValue noargs, result;
	result [0] = -1;
	// Call the function at the far end.
	if (!pXmlClient->execute("MDAXMLGetTCPPortCP", noargs, result))
	{
		if (pXmlClient != 0)
		{
			pXmlClient->close();
			delete pXmlClient;
			pXmlClient = 0;
		}
		return CPCOMM3D_NO_CONNECTION;
	}
	/* get the port value */
	_camera_settings->setDataPort((int)(result[1]));
	return result[0];
}

/*!
* Enable/Disable the Median Filter
*/
int o3dClient::SetMedianFilterStatus(int status)
{
	if (pXmlClient == 0)
		return CPCOMM3D_COMM_NOT_WORKING;

	XmlRpc::XmlRpcValue args, result;
	result [0] = -1;
	args[0] = status;
	// Call the function at the far end.
	if (!pXmlClient->execute("MDAXMLSetMedianFilterStatus", args, result))
	{
		if (pXmlClient != 0)
		{
			pXmlClient->close();
			delete pXmlClient;
			pXmlClient = 0;
		}
		return CPCOMM3D_NO_CONNECTION;
	}
	return result[0];
}

/*!
* Trigger an Image
*/
int o3dClient::TriggerImage()
{
	if (pXmlClient == 0)
		return CPCOMM3D_COMM_NOT_WORKING;

	XmlRpc::XmlRpcValue noargs, result;
	result [0] = -1;
	// Call the function at the far end.
	if (!pXmlClient->execute("MDAXMLTriggerImage", noargs, result))
	{
		if (pXmlClient != 0)
		{
			pXmlClient->close();
			delete pXmlClient;
			pXmlClient = 0;
		}
		return CPCOMM3D_NO_CONNECTION;
	}
	return result[0];
}

/*!
* Enable/Disable the Mean Filter
*/
int o3dClient::SetMeanFilterStatus(int status)
{
	if (pXmlClient == 0)
		return CPCOMM3D_COMM_NOT_WORKING;

	XmlRpc::XmlRpcValue args, result;
	result [0] = -1;
	args[0] = status;
	// Call the function at the far end.
	if (!pXmlClient->execute("MDAXMLSetMeanFilterStatus", args, result))
	{
		if (pXmlClient != 0)
		{
			pXmlClient->close();
			delete pXmlClient;
			pXmlClient = 0;
		}
		return CPCOMM3D_NO_CONNECTION;
	}
	return result[0];
}


//--------------------------------------------------------------------------
/*!
* @brief Get the current IP address by using OS functions related with the
*          hostname (NOT accessing hardware information)
* @param IPbuf
*  [OUT] String containing the read IP address, empty if error happened
* @return 0 if the no errors happened, <0 if errors happened
*/
//--------------------------------------------------------------------------
int o3dClient::readOwnIP(std::string  &IPbuf)
{
	int ret = -1;
#ifdef WIN32
	WORD wVersionRequested;
	WSADATA wsaData;
	PHOSTENT hostinfo;
	char name[255];
	wVersionRequested = MAKEWORD(2, 0);
	/* retrieve IP-Adress of local machine */
	if (WSAStartup(wVersionRequested, &wsaData) == 0)
	{
		if (gethostname(name, sizeof(name)) == 0)
		{
			if ((hostinfo = gethostbyname(name)) != 0)
			{
				IPbuf = std::string(inet_ntoa(*(struct in_addr *) * hostinfo->h_addr_list));
				ret = 0;
			}
			else
			{
				ret = -1;
			}
		}
		else
		{
			ret = -1;
		}
		WSACleanup();
	}
	else
	{
		ret = -1;
	}
#else
	// Read the own ip address
	char stName [20];
	IPbuf.clear();
	memset(stName, 0, 20);
	gethostname(stName, 20);
	struct hostent *hp = (struct hostent *) gethostbyname(stName);
	if (hp == 0)
		ret = -1;
	struct in_addr my_addr;
	memcpy(&(my_addr), hp->h_addr, hp->h_length);
	IPbuf = inet_ntoa(my_addr);
	ret = 0;
#endif
	return ret;
}


int o3dClient::setupSensor()
{
	if ( Connect(_camera_settings->getIP(),
                _camera_settings->getXmlPort()) != CPCOMM3D_NO_ERRORS)
	{
		return -1;
	}

	GetTCPPort();
        T_FrontendData frontend_data;
        _camera_settings->getFrontendData(&frontend_data);
	int res = SetFrontendData(&frontend_data);
	if (-1 != _camera_settings->getTriggerMode())
		SetTrigger(_camera_settings->getTriggerMode());

	SetMedianFilterStatus(_camera_settings->getMedianFilter());
	SetMeanFilterStatus(_camera_settings->getMeanValueFilter());

	
	StartLiveImageServer(_camera_settings->getDataPort(),
            _camera_settings->getIP());

	XmlRpc::XmlRpcValue args, result;
	if (4 != _camera_settings->getTriggerMode()) // software trigger mode
	{
//		Disconnect();
	}

	return 0;
}

void o3dClient::cleanupSensor()
{
    stopReadThread();
    StopLiveImageServer();
    Disconnect();
}

void o3dClient::readData()
{
    timeb _timestruct;
    long StartTime    = 0;
    long EndTime    = 0;
    unsigned int timestamp_old = 0;
    
    try
    {
            // fetch time stamp
            ftime(&_timestruct);
            StartTime = _timestruct.time * 1000 + _timestruct.millitm;
            if (_camera_settings->getTriggerMode() == 4) // software trigger mode
            {
                    TriggerImage();
            }
            else
            {
                    // Poll for next image
                    Sleep(1);
            }

            if (pImageServerClientSocket != 0)
            {
                    /**
                    * Request the image type from sensor
                    */
                    pImageServerClientSocket->sendData(AmountOfImages + 1, strDataSendCommand);
                    for (int i = 0; i < (unsigned int)AmountOfImages; i ++)
                    {
                            o3dDataHeader &img_data_header = getDataHeader(i);
                            //get image from sensor
                            pImageServerClientSocket->ReceiveFrame(IMG_SIZE + sizeof(T_IMAGEHEADER), (char*)pf_ImageBuffer);
                            // get images
                            
                            for (unsigned int p = 0; p < sizeof(T_IMAGEHEADER) / sizeof(float); p++)
                            {
                                    /* swap bytes if needed */
                                    unsigned int dum = ntohl(*reinterpret_cast<long *>(&pf_ImageBuffer[p]));
                                    ((float*)&img_data_header.header)[p] = *(reinterpret_cast<float *>(&dum));
                            }
                            // received the same picture??
                            if (i == 0)
                            {
                                    if (((_camera_settings->getTriggerMode() == 1) || (_camera_settings->getTriggerMode() == 2)) && (img_data_header.OldImageTimeStamp == 0))
                                    {
#ifdef _DEBUG
                                            cout << "First triggered picture" << endl;
#endif
                                            //images = -1;
                                            
                                    }
                                    else if (img_data_header.header.TimeStamp.Seconds*1000 + img_data_header.header.TimeStamp.Useconds == img_data_header.OldImageTimeStamp)
                                    {
                                            // last picture was the same, don't count it
                                            //images--;
                                            
                                    }
                                    else
                                    {
                                            
                                            unsigned int timestamp  = 0;
                                            timestamp  = (unsigned int) img_data_header.header.TimeStamp.Seconds * 1000;
                                            timestamp += (unsigned int)img_data_header.header.TimeStamp.Useconds / 1000;
                                            unsigned int time_diff = timestamp - timestamp_old;
                                            timestamp_old = timestamp;
//                                            std::cout << "Reading image No " << images++;
//                                            std::cout << " error " << header.ErrorCode;
//                                            std::cout << " Time diff: " << time_diff ;
//                                            std::cout << " [ms]" << " Reconnects: " << reconnectCount << std::endl;
                                    }
                            }
                            img_data_header.OldImageTimeStamp = (unsigned long)(img_data_header.header.TimeStamp.Seconds * 1000 + img_data_header.header.TimeStamp.Useconds);
                            _image_data->_time_stamp = img_data_header.OldImageTimeStamp;
                            
                            /* convert the binary/float data to little endian */
                            for (int p = 0; p < IMG_WIDTH*IMG_HEIGHT; p++)
                            {
                                    /* swap bytes if needed */
                                
                                    unsigned int dum = ntohl(*reinterpret_cast<long *>(&pf_ImageBuffer[p+T_IMAGEHEADER_SIZE]));
                                    img_data_header.pf_finalImageBuffer[p] = *(reinterpret_cast<float *>(&dum));

                                   // std::cout << p <<std::endl;
                                   // float d = *(reinterpret_cast<float *>(&dum));
                            }                    
                            
                    }

                   // _camera_settings->setImageHeader(&getDataHeader(dtype_d).header);

                    _image_data->getCameraSettings()->setImageHeader(
                        &getDataHeader(dtype_d).header);

#ifdef O3D_USE_BOOST
                    _sig_new_data(_image_data);
                    _sig_read();                    
#endif
                    _image_data->dataChanged();
            }
            else
            {/* 0 == pImageServerClientSocket ui_TCPPort, str_IP*/
                            if(0 == setupSensor())
                                    reconnectCount++;
            }


            if (_camera_settings->getTriggerMode() == 4)
            {
                    ftime(&_timestruct);
                    EndTime = _timestruct.time * 1000 + _timestruct.millitm;
            }

    }
    catch (SocketClosedException e)
    {
            printf("Error occured SocketClosedException: %s %i \n", e.description().c_str(), e.error());
//            std::cout << "retry it" << std::endl;
            delete pImageServerClientSocket;
            pImageServerClientSocket = 0;
            /* check for Trigger Mode 4 */
    }
    catch (SocketException e)
    {
            printf("Error occured SocketException: %s  %i \n", e.description().c_str(), e.error());
//            std::cout << "retry it" << std::endl;
//            delete pImageServerClientSocket;
//            pImageServerClientSocket = 0;
            cleanupSensor();
            /* check for Trigger Mode 4 */
    }
    catch (...)
    {
            printf("Error occured \n");
//            std::cout << "retry it" << std::endl;
//            delete pImageServerClientSocket;
//            pImageServerClientSocket = 0;
            cleanupSensor();
            /* check for Trigger Mode 4 */
    }
}

float* o3dClient::getData(o3dDataType type)
{
    return getDataHeader(type).pf_finalImageBuffer;
}

float* o3dClient::getData(char type)
{
    return getDataHeader(type).pf_finalImageBuffer;
}

o3dCompleteData* o3dClient::getCompleteData()
{
    return _image_data;
}

o3dCameraSettings* o3dClient::getCameraSettings()
{
    return _camera_settings;
}

o3dDataHeader &o3dClient::getDataHeader(o3dDataType type)
{
    return *_image_data_headers[type];
}

o3dDataHeader &o3dClient::getDataHeader(char type)
{
    return getDataHeader(getDataType(type));
}

o3dDataHeader &o3dClient::getDataHeader(int type)
{
    return getDataHeader(strDataSendCommand[type]);
}

void o3dClient::setDataTypes(std::string type_list)
{
//    if(strDataSendCommand)
//    {
//        delete [] strDataSendCommand;
//    }
    
//    strDataSendCommand = new char[type_list.size()+1];
    
    for(int i=0;i<type_list.size();i++)
    {
        strDataSendCommand[i] = type_list[i];
        //_image_data[getO3DDataType(type_list[i])];
    }
    
    strDataSendCommand[type_list.size()] = 0;
    
    AmountOfImages = type_list.size();
}

#ifdef O3D_USE_BOOST
boost::signals2::signal<void(o3dCompleteData*)>& o3dClient::sigNewData()
{
    return _sig_new_data;
}

boost::signals2::signal<void()>& o3dClient::sigRead()
{
    return _sig_read;
}
#endif

void o3dDataHeader::saveToFile(std::string filename)
{
    FILE *DataFile = fopen(filename.c_str(), "wb");
    if (DataFile == 0)
    {
            return;
    }

    fwrite(&header, sizeof(T_IMAGEHEADER), 1, DataFile);
    fwrite(pf_finalImageBuffer, IMG_SIZE, 1, DataFile);


    fclose(DataFile);
}

void o3dDataHeader::readFromFile(std::string filename)
{
    FILE *DataFile = fopen(filename.c_str(), "rb");
    if (DataFile == 0)
    {
            return;
    }

    fread(&header, sizeof(T_IMAGEHEADER), 1, DataFile);
    fread(pf_finalImageBuffer, IMG_SIZE, 1, DataFile);

    fclose(DataFile);
}


int o3dClient::getReconnectCount()
{
    return reconnectCount;
}

void o3dClient::resetReconnectCount()
{
    reconnectCount=0;
}

void o3dClient::sendFrontendData()
{
    T_FrontendData frontend_data;
    
    _camera_settings->getFrontendData(&frontend_data);
    
    SetFrontendData(&frontend_data);
    
    _camera_settings->setFrontendData(&frontend_data);
}
    
void o3dClient::readFrontendData()
{
    T_FrontendData frontend_data;
    
    GetFrontendData(&frontend_data);
    
    _camera_settings->setFrontendData(&frontend_data);
}

void  o3dClient::setMedianFilterStatus(bool status)
{
    SetMedianFilterStatus(int(status));
}

void  o3dClient::setMeanFilterStatus(bool status)
{
    SetMeanFilterStatus(int(status));
}

#ifdef O3D_USE_BOOST
void o3dClient::startReadThread()
{
    if(!_read_thread)
    {
        boost::mutex::scoped_lock lock(_read_mutex);
        _stop_thread = false;
        _read_thread = new boost::thread(boost::bind(&o3dClient::readLoop,this));
    }
}

void o3dClient::stopReadThread()
{
    if(!_read_thread) return;

    _stop_thread = true;
    boost::mutex::scoped_lock lock(_read_mutex);

    delete _read_thread;
    _read_thread = 0;
}

void o3dClient::readLoop()
{
    boost::mutex::scoped_lock lock(_read_mutex);

    while(!_stop_thread)
    {
        readData();
        boost::this_thread::sleep(boost::posix_time::milliseconds(10));
    }


}
#endif

}//namespace O3D
