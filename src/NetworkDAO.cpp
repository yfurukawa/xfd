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
#include "./NetworkDAO.h"

NetworkDAO::NetworkDAO() : socket_(0) {
}

NetworkDAO::~NetworkDAO() {
}

void NetworkDAO::openInputter(std::string url) {
  std::string hostName;
  std::string portNumber;
  int port;
  unsigned int** addrptr;

  socket_ = socket(AF_INET, SOCK_STREAM, 0);

  if(socket_ < 0) {
    std::cerr << "socket" << std::endl;
  }

  split(url, ':', hostName, portNumber);
  std::istringstream iss(portNumber);
  iss >> port;
  server_.sin_family = AF_INET;
  server_.sin_port = htons(port);
  server_.sin_addr.s_addr = inet_addr(hostName.c_str());

  if(server_.sin_addr.s_addr == 0xffffffff) {
    struct hostent* host;
    host = gethostbyname(hostName.c_str());
    if(host == NULL) {
      if(h_errno == HOST_NOT_FOUND) {
        std::cerr << "host not found : " << hostName << std::endl;
      }
      else {
        std::cerr << hstrerror(h_errno) << std::endl;
      }
    }

    addrptr = (unsigned int **)host->h_addr_list;

    while(*addrptr != NULL) {
      server_.sin_addr.s_addr = *(*addrptr);

      if(connect(socket_, (struct sockaddr*)&server_, sizeof(server_)) == 0) {
        break;
      }
      addrptr++;
    }

    if(*addrptr == NULL) {
      std::cerr <<"connect" << std::endl;
    }
  }
  else {
    if(connect(socket_, (struct sockaddr*)&server_, sizeof(server_)) != 0) {
      std::cerr << "connect" << std::endl;
    }
  }

}

void NetworkDAO::closeInputter() {
  close(socket_);
}

std::string NetworkDAO::readData() {
  char readBuffer[255];
  int n;
  std::string readString;

  memset(readBuffer, 0, sizeof(readBuffer));
  snprintf(readBuffer, sizeof(readBuffer), "GET /job/testJob/lastBuild/api/json HTTP1.1\r\n\r\n");

  n = write(socket_, readBuffer, (int)strlen(readBuffer));

  if(n < 0) {
    std::cerr << "write" << std::endl;
  }

  //while(n > 0) {
    memset(readBuffer, 0, sizeof(readBuffer));
    n = read(socket_, readBuffer, sizeof(readBuffer));
    if(n < 0) {
      std::cerr << "read" << std::endl;
      readString = "No Data";
    }
    else {
      readString = readBuffer;
    }
  //}

  return readString;
}

bool NetworkDAO::isExsist(std::string name) {
  return false;
}

void NetworkDAO::split(std::string url, char delimiter, std::string& hostName,
    std::string& port) {
  std::stringstream ss(url);

    getline(ss, hostName, delimiter);
    getline(ss, port, delimiter);
}
