/*
 * NetworkDAOMock.cpp
 *
 *  Created on: 2015/01/06
 *      Author: yoshi
 */

#include "NetworkDAOMock.h"

NetworkDAOMock::NetworkDAOMock() : message_("No Message"){
    // TODO 自動生成されたコンストラクター・スタブ

}

NetworkDAOMock::~NetworkDAOMock() {
    // TODO Auto-generated destructor stub
}

std::string NetworkDAOMock::readData() {
    return "{\"result\" : \"SUCCESS\"}";
}
