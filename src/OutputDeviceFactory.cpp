/*
 * Copyright
 *
*/
#include "./OutputDeviceFactory.h"

OutputDeviceFactory::~OutputDeviceFactory() {
}

OutputDeviceFactory& OutputDeviceFactory::getInstance() {
    static OutputDeviceFactory instance;
    return instance;
}
