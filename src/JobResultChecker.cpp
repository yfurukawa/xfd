/*
 * Copyright
 *
*/
#include <map>
#include <string>
#include <iostream>
#include "./JobResultChecker.h"
#include "NetworkDAO.h"

JobResultChecker::JobResultChecker() : jobName_(""), networkDao_(NULL) {
}

JobResultChecker::~JobResultChecker() {
    delete networkDao_;
}

JobResultChecker::JobResultChecker(const std::string jobName, NetworkDAO* networkDao) : jobName_(jobName), networkDao_(networkDao) {
}

void JobResultChecker::sendRequestMessageToJenkins() {
    networkDao_->sendRequest("GET /job/" + jobName_ + "/lastBuild/api/json\r\n\r\n");
}

bool JobResultChecker::checkResult() {
    sendRequestMessageToJenkins();
    return judgeJenkinsJobResult();
}

std::string JobResultChecker::getJobName() {
    return jobName_;
}

bool JobResultChecker::judgeJenkinsJobResult() {
    if( parser.parse(networkDao_->readData())["result"] == "\"SUCCESS\"") {
        return true;
    }
    else {
        return false;
    }
}

