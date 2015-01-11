/*
 * Copyright
 *
*/
#include <map>
#include <string>
#include <iostream>
#include "./JobResultChecker.h"
#include "NetworkDAO.h"
#include "NetworkException.h"

JobResultChecker::JobResultChecker(const std::string jobName, NetworkDAO* networkDao) : jobName_(jobName), networkDao_(networkDao) {
}

JobResultChecker::~JobResultChecker() {
    delete networkDao_;
}

std::string JobResultChecker::getJobName() {
    return jobName_;
}

bool JobResultChecker::checkResult() {
    bool result(false);

    try {
        sendRequestMessageToJenkins();
        result = judgeJenkinsJobResult();
    }
    catch(NetworkException& e) {
        throw;
    }
    return result;
}

//////////////////////////////////////////////////////////////
void JobResultChecker::sendRequestMessageToJenkins() {
    try {
        networkDao_->sendRequest("GET /job/" + jobName_ + "/lastBuild/api/json\r\n\r\n");
    }
    catch(NetworkException& e) {
        throw;
    }
}

bool JobResultChecker::judgeJenkinsJobResult() {
    std::string readData("");
    try {
        readData = networkDao_->readData();
    }
    catch(NetworkException& e) {
        throw;
    }

    if( isJsonString(readData)) {
        return parser.parse(readData)["result"] == "\"SUCCESS\""?true:false;
    }
    return false;
}

bool JobResultChecker::isJsonString(std::string readData) {
    return readData[0] == '{';
}

JobResultChecker::JobResultChecker() : jobName_(""), networkDao_(NULL) {
}

