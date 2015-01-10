/*
 * NetworkDAOMock.h
 *
 *  Created on: 2015/01/06
 *      Author: yoshi
 */

#ifndef NETWORKDAOMOCK_H_
#define NETWORKDAOMOCK_H_

#include "NetworkDAO.h"

enum resultMode{success, fail, unknown};

class NetworkDAOMock : public NetworkDAO {
    private:
        std::string message_;
        std::string jsonString_;
    public:
        NetworkDAOMock();
        virtual ~NetworkDAOMock();
        virtual void openInputter( std::string name ){};
        virtual void closeInputter(){};
        virtual std::string readData();
        virtual bool isExsist ( std::string name ){ return true; };
        void sendRequest(const std::string& requestMessage) { message_ = requestMessage; };
        std::string getRequestedMessage() { return message_; };
        void setResult(enum resultMode setMode);
};

#endif /* NETWORKDAOMOCK_H_ */
