/*
 * NetworkDAOMock.cpp
 *
 *  Created on: 2015/01/06
 *      Author: yoshi
 */

#include "NetworkDAOMock.h"

NetworkDAOMock::NetworkDAOMock() : message_("No Message"), jsonString_(""){
    setResult(true);
}

NetworkDAOMock::~NetworkDAOMock() {
    // TODO Auto-generated destructor stub
}

std::string NetworkDAOMock::readData() {
    return jsonString_;
}

void NetworkDAOMock::setResult(bool result) {
    if(result) {
        jsonString_  = "{\"actions\":[{\"causes\":[{\"shortDescription\":\"Started by user anonymous\",\"userId\":null,\"userName\":\"anonymous\"}]},{\"failCount\":0,\"skipCount\":0,\"totalCount\":1,\"urlName\":\"testReport\"}],\"artifacts\":[],\"building\":false,\"description\":null,\"duration\":129,\"estimatedDuration\":1017,\"executor\":null,\"fullDisplayName\":\"testJob #2\",\"id\":\"2015-01-05_14-39-04\",\"keepLog\":false,\"number\":2,\"result\":\"SUCCESS\",\"timestamp\":1420436344000,\"url\":\"http://127.0.0.1:8080/job/testJob/2/\",\"builtOn\":\"\",\"changeSet\":{\"items\":[],\"kind\":null},\"culprits\":[]}";
    }
    else {
        jsonString_ = "{\"actions\":[{\"causes\":[{\"shortDescription\":\"Started by user anonymous\",\"userId\":null,\"userName\":\"anonymous\"}]},{\"failCount\":0,\"skipCount\":0,\"totalCount\":1,\"urlName\":\"testReport\"}],\"artifacts\":[],\"building\":false,\"description\":null,\"duration\":129,\"estimatedDuration\":1017,\"executor\":null,\"fullDisplayName\":\"testJob #2\",\"id\":\"2015-01-05_14-39-04\",\"keepLog\":false,\"number\":2,\"result\":\"FAIL\",\"timestamp\":1420436344000,\"url\":\"http://127.0.0.1:8080/job/testJob/2/\",\"builtOn\":\"\",\"changeSet\":{\"items\":[],\"kind\":null},\"culprits\":[]}";
    }
}
