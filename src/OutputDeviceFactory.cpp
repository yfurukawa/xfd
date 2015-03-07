/*
 * Copyright
 *
*/
#include "./OutputDeviceFactory.h"

#include "GpioContinuousOutputter.h"

OutputDeviceFactory::~OutputDeviceFactory() {
}

void OutputDeviceFactory::setCommandLineArguments(int* argc, char*** argv) {
    argc_ = argc;
    argv_ = argv;
}

