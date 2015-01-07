/*
 * Copyright
 *
*/
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
