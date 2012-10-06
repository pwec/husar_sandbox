/*
----------------------------------------------------------------------------
    File:          clientsocket.h
    Author:        deegech/TOE/ifm
    Creation date: 31-Jan-2008
    Version:       $Rev: 11832 $
    Last change:   $Date: 2009-01-15 13:26:14 +0100 (Do, 15 Jan 2009) $
    Description:   header file for socket connection to sensor


    Copyright (C) 2008 ifm electronic GmbH, deegech/TOE/ifm
    See accompanied file licence.txt for license information.
----------------------------------------------------------------------------
*/
/* $Id: clientsocket.h 11832 2009-01-15 12:26:14Z deegech $ */

#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#if _WINDOWS || _WIN32 //> 1000
#include <winsock2.h>
#else
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#ifndef INVALID_SOCKET
#define INVALID_SOCKET  -1
#endif
#ifndef SOCKET_ERROR
#define SOCKET_ERROR  -1
#endif
#endif

#ifndef WIN32
#define SOCKET int
#endif

#include <string>

namespace o3d{
/*!
 * @brief Client socket exception.
 */
class SocketException
{
public:
    /*!
     * @param s
     * Descriptive string for the exception.
     */
    SocketException(std::string s, int error) : m_s(s), m_error(error) {};
    ~SocketException() {};

    /*!
     * @brief Get description string
     * @return Descriptive string of the exception.
     */
    std::string description()
    {
        return m_s;
    };
    int error()
    {
        return m_error;
    };

private:
    std::string m_s;
    int m_error;
};

/*!
 * @brief Client socket closed exception
 */
class SocketClosedException : public SocketException
{
public:
    /*!
     * @param s
     * Descriptive string for the exception.
     */
    SocketClosedException(std::string s) : SocketException(s, 0) {};
};

/*!
 * @brief Client socket
 */
class ClientSocket
{
public:
    /*!
     * @brief Client socket initialization.
     * @param ipaddr
     * IP address to connect to e.g. "127.0.0.1"
     * @param port
     * TCP/IP port to use, e.g. "8080"
     */
    ClientSocket(const char* addr, int port);
    ~ClientSocket();

    void sendData(int byte_size, const void* data);

    /*!
     * @brief receive a data frame.
     * @param frame_byte_size
     * Number of bytes in the frame.
     * @param buffer
     * Buffer to save frame to.
     * @throws SocketException
     */
    int ReceiveFrame(int frame_byte_size, char *buffer);

    /*! Receive a 4 byte integer.
     @throws SocketException
    */
    int ReceiveInt(int &toRec);

    /*! Receive a 2 byte unsigned short value.
     @throws SocketException
    */
    int ReceiveU16(unsigned short &toRec);

    /*! \return The current state of the socket. */
    bool isOK()
    {
        return _OK;
    };

private:
#ifdef WIN32
    WSAData wsaData;
#endif
    SOCKET sd;

    /*!
     * @param nRemoteAddr
     * IP address to connet to.
     * @param nPort
     * TCP/IP port to connect to.
     * @return
     * On success a descriptor referencing the new socket is return,
     *  INVALID_SOCKET else.
     *
     * Connects to a given address, on a given port, both of which must be
     * in network byte order.  Returns newly-connected socket if we succeed,
     * or INVALID_SOCKET if we fail.
     */
    SOCKET EstablishConnection(u_long nRemoteAddr, u_short nPort);

    /*!
     * Gracefully shuts the connection sd down.
     * @return Returns true if we're successful, false otherwise.
     */
    bool ShutdownConnection(SOCKET sd);

    bool _OK;
};
}//namespace O3D
#endif // CLIENT_SOCKET_H
/*--- END OF FILE  -------------------------------------------------------*/
