/*
----------------------------------------------------------------------------
File:          clientsocket.cpp
Author:        deegech/TOE/ifm
Creation date: 31-Jan-2008
Version:       $Rev: 12444 $
Last change:   $Date: 2009-02-17 17:30:30 +0100 (Di, 17 Feb 2009) $
Description:   C++ wrapper class for socket communication


Copyright (C) 2008 ifm electronic GmbH, deegech/TOE/ifm
See accompanied file licence.txt for license information.
----------------------------------------------------------------------------
*/
/* $Id: clientsocket.cpp 12444 2009-02-17 16:30:30Z deegech $ */

#include "../include/communication/clientsocket.h"

namespace o3d{

/*!
* Startup Windows socket and Establish connection
*/
ClientSocket::ClientSocket(const char* addr, int port)
{
#ifdef WIN32
	int code = WSAStartup(MAKEWORD(1, 1), &wsaData);
#else
	int code = 0;
#endif
	sd = EstablishConnection(inet_addr(addr), htons(port));
	_OK = (code == 0) && sd != INVALID_SOCKET;
}


/*!
* Shutdown connection and Windows socket.
*/
ClientSocket::~ClientSocket()
{
	if (sd != INVALID_SOCKET) ShutdownConnection(sd);
#ifdef WIN32
	WSACleanup();
#endif
}

/*!
* Send data with byte size.
*/
void ClientSocket::sendData(int byte_size, const void* data)
{
	int ret = send(sd, (char*) data, byte_size, 0) ;
	if (ret == SOCKET_ERROR)
	{
#ifdef WIN32
		int error = WSAGetLastError();
#else
		int error = errno;
#endif
		throw SocketException("send error", error);
	}
}


/*!
* Build up a connection to Sensor.
* Create a socket and connect to Sensor.
*/
SOCKET ClientSocket::EstablishConnection(u_long nRemoteAddr, u_short nPort)
{
	// Create a stream socket
	SOCKET sd = socket(PF_INET, SOCK_STREAM, 0);
	if (sd != INVALID_SOCKET)
	{
		sockaddr_in sinRemote;
		sinRemote.sin_family = AF_INET;
		sinRemote.sin_addr.s_addr = nRemoteAddr;
		sinRemote.sin_port = nPort;
		int r = connect(sd, (sockaddr*) & sinRemote, sizeof(sockaddr_in));
		if (r == SOCKET_ERROR) sd = INVALID_SOCKET;
	}
	return sd;
}

/*!
* Gracefully shuts the connection sd down.  Returns true if we're
* successful, false otherwise.
*/
bool ClientSocket::ShutdownConnection(SOCKET sd)
{
#ifdef WIN32
	// Disallow any further data sends.  This will tell the other side
	// that we want to go away now.  If we skip this step, we don't
	// shut the connection down nicely.
	// This function is only available for winsock2 sockets.
	if (shutdown(sd, SD_SEND) == SOCKET_ERROR)
	{
		return false;
	}
	// Close the socket.
	if (closesocket(sd) == SOCKET_ERROR)
	{
		return false;
	}
#else
	if (SOCKET_ERROR == close(sd))
	{
		return false;
	}
#endif

	return true;
}

/*!
* Receive an integer.
*/
int ClientSocket::ReceiveInt(int &toRec)
{
	int res = ReceiveFrame(sizeof(int), (char*) & toRec);
	toRec = ntohl(toRec);
	return res;
}

/*!
* Receive an unsigned short (u16).
*/
int ClientSocket::ReceiveU16(unsigned short &toRec)
{
	int res = ReceiveFrame(sizeof(unsigned short), (char*) & toRec);
	toRec = ntohs(toRec);
	return res;
}

/*!
* Receive a frame of given length and save it to buffer.
*/
int ClientSocket::ReceiveFrame(int frame_byte_size, char *buffer)
{
	int total_bytes = 0;
	fd_set fdReadSocket;
	struct timeval m_TcpTimeout;
	int iRetSelect = 0;
	int new_bytes = 0;
	// Set the socket descriptor
	FD_ZERO (&fdReadSocket);
	FD_SET (sd, &fdReadSocket);  
	m_TcpTimeout.tv_usec = 0;
	m_TcpTimeout.tv_sec  = 5;
	iRetSelect = select (sd+1, &fdReadSocket, NULL, NULL, &m_TcpTimeout);
	if(iRetSelect == 0 || !FD_ISSET (sd, &fdReadSocket))
	{
		/* nothing to read. No request? */ 
		new_bytes = SOCKET_ERROR;
	}
	else if(iRetSelect < 0)
	{
		new_bytes = SOCKET_ERROR;
	}
	else
	{
		while (total_bytes < frame_byte_size)
		{
			/*check what data shall be sent*/
			new_bytes = recv(sd, buffer + total_bytes, frame_byte_size - total_bytes, 0);
			if (new_bytes == SOCKET_ERROR)
			{
				break;
			}
			if (new_bytes == 0) 
				throw SocketClosedException("connection closed by peer");
			total_bytes += new_bytes;
		}
	}
	if(frame_byte_size != total_bytes)
	{
#ifdef WIN32
		int error = WSAGetLastError();
#else
		int error = errno;
#endif
		throw SocketException("receive error", error);
	}
	return total_bytes;
}
}//namespace O3D
/*--- END OF FILE  -------------------------------------------------------*/
