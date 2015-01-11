/*
 * NetworkException.h<br>
 * ネットワークアクセスの例外クラス
 *
 *  Created on: 2015/01/10
 *      Author: yoshi
 */

#ifndef NETWORKEXCEPTION_H_
#define NETWORKEXCEPTION_H_

#include <bits/ios_base.h>
#include <string>

class NetworkException: public std::ios_base::failure {
    public:
        NetworkException(const std::string& cause)
            : std::ios_base::failure("cause : " + cause) {}
};

#endif /* NETWORKEXCEPTION_H_ */
