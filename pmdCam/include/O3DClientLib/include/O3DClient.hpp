/* 
 * File:   O3DClient.hpp
 * Author: Maciek
 *
 * Created on 13 maj 2010, 22:37
 */

#ifndef _O3DCLIENTLIB_HPP
#define	_O3DCLIENTLIB_HPP

#include "o3dConfig.h"

#include <string>
#include <map>

#ifdef O3D_USE_BOOST
#include <boost/signals2.hpp>
#include <boost/thread.hpp>
#endif

#include <o3dDataTypes.hpp>


#if defined(_WINDOWS) || defined(_WIN32)
# pragma warning(disable:4996)  // disable warnings
# pragma warning(disable:4244)  // disable warnings
#else
# define Sleep(x) usleep(x*1000)
#endif

namespace XmlRpc{ class XmlRpcClient;}

#define IMG_SIZE sizeof(float) * IMG_HEIGHT * IMG_WIDTH
#define T_IMAGEHEADER_SIZE sizeof(T_IMAGEHEADER) / sizeof(float)

namespace o3d{

class o3dCompleteData;
class ClientSocket;
struct o3dDataHeader;
struct T_FrontendData;
class o3dCameraSettings;

class o3dClient {
public:
    o3dClient();
    virtual ~o3dClient();

    int setupSensor();
    void cleanupSensor();

    bool connected();

    void readData();

    float* getData(o3dDataType type);
    float* getData(char type);

    o3dCompleteData* getCompleteData();

    o3dCameraSettings* getCameraSettings();
    
    void setDataTypes(std::string type_list);

    int getReconnectCount();
    void resetReconnectCount();

    void sendFrontendData();
    void readFrontendData();

    void  setMedianFilterStatus(bool status);
    void  setMeanFilterStatus(bool status);

    void startReadThread();
    void stopReadThread();
    
#ifdef O3D_USE_BOOST
    boost::signals2::signal<void(o3dCompleteData*)>& sigNewData();
    boost::signals2::signal<void()>& sigRead();
#endif
    
private:

    std::map<o3dDataType,o3dDataHeader*> _image_data_headers;

    o3dCompleteData* _image_data;

    o3dCameraSettings* _camera_settings;

    bool _connected;

    char strDataSendCommand[20];

    int AmountOfImages;

    int reconnectCount;

    XmlRpc::XmlRpcClient *pXmlClient;

    std::string OwnIpAddress;
    ClientSocket* pImageServerClientSocket;

    float *pf_ImageBuffer;

#ifdef O3D_USE_BOOST
    boost::thread* _read_thread;
    boost::mutex _read_mutex;
    bool _stop_thread;

    boost::signals2::signal<void(o3dCompleteData*)> _sig_new_data;
    boost::signals2::signal<void()> _sig_read;
#endif

    o3dDataHeader& getDataHeader(o3dDataType type);
    o3dDataHeader& getDataHeader(char type);
    o3dDataHeader& getDataHeader(int type);

    int  TriggerImage();
    int  SetFrontendData(T_FrontendData *p_FrontendData);
    int  GetFrontendData(T_FrontendData *p_FrontendData);
    int  SetMedianFilterStatus(int status);
    int  SetMeanFilterStatus(int status);
    int  SetTrigger(int Mode);
    
    int  StopLiveImageServer();
    int  StartLiveImageServer(int i_Port, std::string pIP);
    int  Disconnect();
    int  Connect(std::string pIP,  unsigned int iXMLPort);
    int  GetTCPPort();    
    int  readOwnIP(std::string  &IPbuf);

    void readLoop();

};
} //namespace O3D
#endif	/* _O3DCLIENTLIB_HPP */

