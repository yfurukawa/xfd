/*
 * Copyright
 *
*/
#include <iostream>
#include "./Conductor.h"
#include "JobResultChecker.h"
#include "NetworkDAO.h"

Conductor::Conductor() : checkInterval_(0), baseUrl_("") {
    initializeConfiguration();
}

Conductor::~Conductor() {
}

void Conductor::initializeConfiguration() {
    checkInterval_ = configurator_.getCheckInterval();
    baseUrl_ = configurator_.getBaseURL();
    jobs_ = configurator_.getJobs();

    for(std::vector<std::string>::iterator iter = jobs_.begin(); iter < jobs_.end(); ++iter) {
        resultChecker_.push_back(new JobResultChecker(*iter, new NetworkDAO(baseUrl_)));
    }
}

bool Conductor::checkJobResult() {
    bool result(true);
    for(std::vector<JobResultChecker*>::iterator iter = resultChecker_.begin(); iter < resultChecker_.end(); ++iter) {
        result &= (*iter)->checkResult();
    }
    return result;
}

void Conductor::execute() {
    bool result(false);

    result = checkJobResult();
    if(result) {
        std::cout << "Success" << std::endl;
    }
    else {
        std::cout << "Broken" << std::endl;
    }
}
