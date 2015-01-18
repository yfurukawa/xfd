/*
 * Copyright
 *
 */
#include "wiringPi.h"
#include "GpioContinuousOutputter.h"
#include "OutputDeviceException.h"
#include "utility.h"


int GpioContinuousOutputter::portNumber_ = 21;
enum status GpioContinuousOutputter::status_ = SUCCESS;
bool GpioContinuousOutputter::isFailConditionContinue_ = false;


GpioContinuousOutputter::GpioContinuousOutputter(std::string name) : deviceName_(name) {
}

void GpioContinuousOutputter::outputContents(std::string outputName,
        std::string contents) {
    if(contents == "success") {
        status_ = SUCCESS;
        isFailConditionContinue_ = false;
    }
    else {
        status_ = FAIL;
    }
}

GpioContinuousOutputter::~GpioContinuousOutputter() {
}


void GpioContinuousOutputter::initializeDevice() {
    if( wiringPiSetupGpio() == -1) {
        throw OutputDeviceException("GPIO");
    }
    std::string device("");
    std::string port("");
    util::split(deviceName_, ':', device, port);
    portNumber_ = util::stringToInt(port);
    pinMode(portNumber_, OUTPUT);

    pthread_t threadId(0);

    if(threadId ==0) {
        pthread_create(&threadId, NULL, &GpioContinuousOutputter::run, NULL);
    }
}

void* GpioContinuousOutputter::run(void* pParameter) {
    while(true) {
        if(status_ == SUCCESS) {
            digitalWrite(portNumber_, OFF );
        }
        else if ( (!isFailConditionContinue_) && (status_ != SUCCESS) ) {
            digitalWrite(portNumber_, ON);
            delay(5000);
            digitalWrite(portNumber_, OFF);
            isFailConditionContinue_ = true;
        }
    }
    return NULL;
}
