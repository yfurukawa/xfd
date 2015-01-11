/*
 * Copyright
 *
 */
#include <iostream>
#include "Conductor.h"
#include "Configurator.h"
#include "JobResultChecker.h"
#include "NetworkDAO.h"
#include "NetworkException.h"

Conductor::Conductor() : configurator_(NULL), checkInterval_(0), baseUrl_(""), bufferLength_byte_(1024) {
    initializeConfiguration();
}

void Conductor::execute() {
    bool result(false);

    result = tallyJobResult();
    if(result) {
        std::cout << "Success" << std::endl;
    }
    else {
        std::cout << "Broken" << std::endl;
    }
}

////////////////////////////////////////////////
Conductor::~Conductor() {
}

void Conductor::initializeConfiguration() {
    try {
        configurator_ = new Configurator("/usr/local/etc/xfd.conf");
        configurator_->readConfigurationData();
    }
    catch(std::string& e){
        std::cerr << e << std::endl;
        exit(1);
    }
    checkInterval_ = configurator_->getCheckInterval();
    baseUrl_ = configurator_->getBaseURL();
    jobs_ = configurator_->getJobs();

    for(std::vector<std::string>::iterator iter = jobs_.begin(); iter < jobs_.end(); ++iter) {
        resultChecker_.push_back(new JobResultChecker(*iter, new NetworkDAO(baseUrl_, bufferLength_byte_)));
    }
}

bool Conductor::tallyJobResult() {
    bool result(true);
    for(std::vector<JobResultChecker*>::iterator iter = resultChecker_.begin(); iter < resultChecker_.end(); ++iter) {
        try {
            result = result && (*iter)->checkResult();
        }
        catch(NetworkException& e) {
            std::cout << e.what() << std::endl;
            exit(1);
        }
    }
    return result;
}
