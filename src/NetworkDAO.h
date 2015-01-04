/**
 * NetworkDAO.h<br>
 * Copyright
 *
 */

#ifndef NETWORKDAO_H_
#define NETWORKDAO_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include "IInputter.h"

class NetworkDAO : public IInputter {
  protected:
    int socket_;
    struct sockaddr_in server_;
  public:
    //! Constractor
    NetworkDAO();
    //! Destructor
    virtual ~NetworkDAO();

    virtual void openInputter( std::string url );
    virtual void closeInputter();
    virtual std::string readData();
    virtual bool isExsist ( std::string name );

  protected:
    void split(std::string url, char delimiter, std::string& hostName, std::string& port);
  private:
};

#endif  // NETWORKDAO_H_
