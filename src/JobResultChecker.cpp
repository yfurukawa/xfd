/*
 * Copyright
 *
*/
#include "./JobResultChecker.h"

JobResultChecker::JobResultChecker() : jobName_("") {
}

JobResultChecker::~JobResultChecker() {
}

JobResultChecker::JobResultChecker(const std::string jobName) : jobName_(jobName) {
}

std::string JobResultChecker::getJobName() {
    return jobName_;
}
