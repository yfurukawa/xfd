/*
 * NetworkDAOSpy.h
 *
 *  Created on: 2015/01/04
 *      Author: yoshi
 */

#ifndef NETWORKDAOSPY_H_
#define NETWORKDAOSPY_H_

#include "NetworkDAO.h"

class NetworkDAOSpy: public NetworkDAO {
  public:
    NetworkDAOSpy();
    virtual ~NetworkDAOSpy();
    int getSocket() { return socket_; };
};

#endif /* NETWORKDAOSPY_H_ */
