/*
 * Copyright
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <exception>
#include "NetworkDAO.h"
#include "NetworkException.h"

NetworkDAO::NetworkDAO() : socket_(0), readBufferLength_byte_(1024) {
}

NetworkDAO::NetworkDAO(int size) : socket_(0), readBufferLength_byte_(size) {
}

NetworkDAO::~NetworkDAO() {
}

void NetworkDAO::openInputter(std::string url) {
    unsigned int** addrptr;

    prepareSocket();
    initializeServerInformation(url);

    if (!isSuccessIPAddressResolution()) {
        addrptr = (unsigned int **)resolveIPAddressWithHostName(url)->h_addr_list;

        while(*addrptr != NULL) {
            server_.sin_addr.s_addr = *(*addrptr);

            if(connect(socket_, (struct sockaddr*)&server_, sizeof(server_)) == 0) {
                break;
            }
            addrptr++;
        }

        if(*addrptr == NULL) {
            throw NetworkException("Server Connection Error with host name");
        }
    }
    else {
        if(connect(socket_, (struct sockaddr*)&server_, sizeof(server_)) != 0) {
            throw NetworkException("Server Connection Error with IP Address");;
        }
    }

}

void NetworkDAO::closeInputter() {
    close(socket_);
}

std::string NetworkDAO::readData() {
    char readBuffer[readBufferLength_byte_];
    std::string readString;
    memset(readBuffer, 0, sizeof(readBuffer));

    int readSize(read(socket_, readBuffer, sizeof(readBuffer)));

    if( readSize < 0 ) {
        throw NetworkException("Data receiving error");
    }
    else if( readSize > readBufferLength_byte_ ) {
        throw NetworkException("Buffer Over Flow");
    }
    else {
        readString = readBuffer;
    }

    return readString;
}

bool NetworkDAO::isExsist(std::string name) {
    return false;
}

void NetworkDAO::sendRequest(const std::string& requestMessage) {
    if(write(socket_, requestMessage.c_str(), requestMessage.size()) < 0){
        throw NetworkException("Request message send error");
    }
}

///////////////////////////////////////////////////////////////////////
void NetworkDAO::prepareSocket() {
    socket_ = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_ < 0) {
        throw NetworkException("Socket initialization error");
    }
}

void NetworkDAO::initializeServerInformation(const std::string& url) {
    server_.sin_family = AF_INET;
    server_.sin_port = htons(substringPortNumberFromConfiguredURL(url));
    server_.sin_addr.s_addr = inet_addr(substringHostNameFromconfiguredURL(url).c_str());
}

std::string NetworkDAO::substringHostNameFromconfiguredURL(const std::string& url) {
    std::string hostName;
    std::string portNumber;

    split(url, ':', hostName, portNumber);

    return hostName;
}

int NetworkDAO::substringPortNumberFromConfiguredURL(const std::string& url) {
    std::string hostName;
    std::string portNumber;
    int port;

    split(url, ':', hostName, portNumber);
    std::istringstream iss(portNumber);
    iss >> port;

    return port;
}

bool NetworkDAO::isSuccessGethostbyname(struct hostent* host) {
    return host != NULL;
}

bool NetworkDAO::isSuccessIPAddressResolution() {
    return server_.sin_addr.s_addr != 0xffffffff;
}

struct hostent* NetworkDAO::resolveIPAddressWithHostName(const std::string& url) {
    struct hostent* host = gethostbyname(substringHostNameFromconfiguredURL(url).c_str());
    if (!isSuccessGethostbyname(host)) {
        if (h_errno == HOST_NOT_FOUND) {
            throw NetworkException("host not found : " + substringHostNameFromconfiguredURL(url));
        }
        else {
            throw NetworkException(hstrerror(h_errno));
        }
    }
    return host;
}

void NetworkDAO::split(std::string url, char delimiter, std::string& hostName,
        std::string& port) {
    std::stringstream ss(url);

    getline(ss, hostName, delimiter);
    getline(ss, port, delimiter);
}

