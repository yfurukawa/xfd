/*
 * Copyright
 *
 */
#include "wiringPi.h"
#include "GpioOutputter.h"
#include "OutputDeviceException.h"
#include "utility.h"

#define ON 1
#define OFF 0

int GpioOutputter::portNumber_ = 21;
enum status GpioOutputter::status_ = SUCCESS;
bool GpioOutputter::isFailConditionContinue_ = false;

GpioOutputter::GpioOutputter(std::string name) : deviceName_(name) {
}

GpioOutputter::~GpioOutputter() {
}

void GpioOutputter::outputContents(std::string outputName,
        std::string contents) {

    if(contents == "success") {
        status_ = SUCCESS;
        isFailConditionContinue_ = false;
    }
    else {
        status_ = FAIL;
    }
}

void GpioOutputter::initializeDevice() {
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
        pthread_create(&threadId, NULL, &GpioOutputter::run, NULL);
    }
}


void* GpioOutputter::run(void* pParameter) {
    while(true) {
        if(status_ == SUCCESS) {
            digitalWrite(portNumber_, OFF );
        }
        else if ( (!isFailConditionContinue_) && (status_ != SUCCESS) ) {
            for(int ringingTimes = 0; ringingTimes < 5; ++ringingTimes) {
                digitalWrite(portNumber_, ON);
                delay(500);
                digitalWrite(portNumber_, OFF);
                delay(500);
            }
            isFailConditionContinue_ = true;
        }
    }
    return 0;
}
