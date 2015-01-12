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

GpioOutputter::GpioOutputter(std::string name) : portNumber_(5), deviceName_(name) {
//    initializeDevice(name);
}

GpioOutputter::~GpioOutputter() {
}

void GpioOutputter::outputContents(std::string outputName,
        std::string contents) {
    if(contents == "success") {
        digitalWrite(portNumber_, OFF );
    }
    else {
        digitalWrite(portNumber_, ON );
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
}
