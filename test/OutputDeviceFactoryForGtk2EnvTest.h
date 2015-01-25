#ifndef OUTPUTDEVICEFACTORYFORGTK2ENVTEST_H_
#define OUTPUTDEVICEFACTORYFORGTK2ENVTEST_H_

#include <gtest/gtest.h>
#include "OutputDeviceFactoryForGtk2Env.h"

class OutputDeviceFactoryForGtk2EnvTest : public ::testing::Test {
protected:
	OutputDeviceFactoryForGtk2Env* sut;
	void SetUp();
	void TearDown();

public:
	OutputDeviceFactoryForGtk2EnvTest();
	virtual ~OutputDeviceFactoryForGtk2EnvTest();

};

#endif
