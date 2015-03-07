/*
 * Copyright
 *
*/
#include "./OutputDeviceFactoryForGtk2Env.h"

bool OutputDeviceFactoryForGtk2Env::destroyed_ = false;

OutputDeviceFactory* OutputDeviceFactory::getInstance() {
    static OutputDeviceFactoryForGtk2Env instance;
    if( OutputDeviceFactoryForGtk2Env::isDestroyed() ){
        (void) new(&instance) OutputDeviceFactoryForGtk2Env;
    }

    return &instance;
}

OutputDeviceFactoryForGtk2Env::OutputDeviceFactoryForGtk2Env() {

}

OutputDeviceFactoryForGtk2Env::~OutputDeviceFactoryForGtk2Env() {
	destroyed_ = true;
}

std::vector<IOutputter*> OutputDeviceFactoryForGtk2Env::getOutputterList(std::vector<std::string> deviceType) const {
    std::vector<IOutputter*> outputter;
    for(std::vector<std::string>::iterator iter = deviceType.begin(); iter != deviceType.end(); ++iter) {
        if(*iter == "gtk2") {
            outputter.push_back(new Gtk2Outputter(argc_, argv_));
        }
        else if((*iter).find("GPIO", 0) != std::string::npos) {
            outputter.push_back(new GpioOutputter(*iter));
        }
    }
    return outputter;
}

bool OutputDeviceFactoryForGtk2Env::isDestroyed() {
    return OutputDeviceFactoryForGtk2Env::destroyed_;
}
