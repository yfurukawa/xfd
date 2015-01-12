/*
 * Copyright
 *
 */
#include <iostream>
#include <string>
#include <unistd.h>
#include "Conductor.h"
#include "Configurator.h"
#include "JobResultChecker.h"
#include "NetworkDAO.h"
#include "NetworkException.h"
#include "IOutputter.h"
#include "GtkOutputter.h"

Conductor::Conductor() : configurator_(NULL), checkInterval_(0), baseUrl_(""), bufferLength_byte_(1024),
    configFile_("/usr/local/etc/xfd.conf") {
}

Conductor::Conductor(const std::string& configFile) : configurator_(NULL), checkInterval_(0), baseUrl_(""), bufferLength_byte_(1024),
    configFile_(configFile) {
}

void Conductor::execute(int* argc, char*** argv) {

    IOutputter* outputter;
    outputter = new GtkOutputter(argc, argv);
    outputter->outputContents("", "success");
    try {
        initializeConfiguration();
    }
    catch(const std::string& message) {
        std::cerr << message << std::endl;
    }

    bool result(false);

    do {
        try{
            result = tallyJobResult();
            if(result) {
                std::cout << "success" << std::endl;
              }
            else {
                std::cout << "fail" << std::endl;
              }
            sleep(checkInterval_);
         }
        catch(const NetworkException& e) {
            std::cerr << e.what() << std::endl;
         }
        catch(const std::string& message) {
            std::cerr << message << std::endl;
         }
        catch(...) {
            std::cerr << "Caught Unknown Exception" << std::endl;
         }
    } while(checkInterval_ != 0);
}

////////////////////////////////////////////////
Conductor::~Conductor() {
}

void Conductor::initializeConfiguration() {
    try {
        configurator_ = new Configurator(configFile_);
        configurator_->readConfigurationData();
    }
    catch(std::string& e){
        throw;
    }
    checkInterval_ = configurator_->getCheckInterval();
    baseUrl_ = configurator_->getBaseURL();
    jobs_ = configurator_->getJobs();

    for(std::vector<std::string>::iterator iter = jobs_.begin(); iter < jobs_.end(); ++iter) {
        resultChecker_.push_back(new JobResultChecker(*iter, baseUrl_, new NetworkDAO(bufferLength_byte_)));
    }
}

bool Conductor::tallyJobResult() {
    bool result(true);
    for(std::vector<JobResultChecker*>::iterator iter = resultChecker_.begin(); iter < resultChecker_.end(); ++iter) {
        try {
            result = result && (*iter)->checkResult();
        }
        catch(NetworkException& e) {
            throw;
        }
    }
    return result;
}
