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

JobResultChecker::JobResultChecker() : jobName_(""), networkDao_(NULL) {
}

JobResultChecker::~JobResultChecker() {
    delete networkDao_;
}

JobResultChecker::JobResultChecker(const std::string jobName, NetworkDAO* networkDao) : jobName_(jobName), networkDao_(networkDao) {
}

void JobResultChecker::sendRequestMessageToJenkins() {
    try {
        networkDao_->sendRequest("GET /job/" + jobName_ + "/lastBuild/api/json\r\n\r\n");
    }
    catch(NetworkException& e) {
        throw;
    }
}

bool JobResultChecker::checkResult() {
    bool result(false);
    sendRequestMessageToJenkins();
    try {
        result = judgeJenkinsJobResult();
    }
    catch(NetworkException& e) {
        throw;
    }
    return result;
}

std::string JobResultChecker::getJobName() {
    return jobName_;
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
 //       std::cout << readData << std::endl;
        return parser.parse(readData)["result"] == "\"SUCCESS\""?true:false;
    }
    return false;
}

bool JobResultChecker::isJsonString(std::string readData) {
    return readData[0] == '{';
}

