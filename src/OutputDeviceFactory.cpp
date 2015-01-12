/*
 * Copyright
 *
*/
#include "./OutputDeviceFactory.h"
#include "GpioOutputter.h"
#include "GtkOutputter.h"

OutputDeviceFactory::~OutputDeviceFactory() {
}

OutputDeviceFactory& OutputDeviceFactory::getInstance() {
    static OutputDeviceFactory instance;
    return instance;
}

void OutputDeviceFactory::setCommandLineArguments(int* argc, char*** argv) {
    argc_ = argc;
    argv_ = argv;
}

std::vector<IOutputter*> OutputDeviceFactory::getOutputterList(std::vector<std::string> deviceType) {
    std::vector<IOutputter*> outputter;
    for(std::vector<std::string>::iterator iter = deviceType.begin(); iter != deviceType.end(); ++iter) {
        if(*iter == "gtk") {
            outputter.push_back(new GtkOutputter(argc_, argv_));
        }
        else if((*iter).find("GPIO", 0) != std::string::npos) {
            outputter.push_back(new GpioOutputter(*iter));
        }
    }
    return outputter;
}
