#ifndef OUTPUTDEVICEFACTORYFORGTK3ENVTEST_H_
#define OUTPUTDEVICEFACTORYFORGTK3ENVTEST_H_

#include <gtest/gtest.h>
#include "OutputDeviceFactoryForGtk3Env.h"

class OutputDeviceFactoryForGtk3EnvTest : public ::testing::Test {
protected:
	OutputDeviceFactoryForGtk3Env* sut;
	void SetUp();
	void TearDown();

public:
	OutputDeviceFactoryForGtk3EnvTest();
	virtual ~OutputDeviceFactoryForGtk3EnvTest();

};

#endif
