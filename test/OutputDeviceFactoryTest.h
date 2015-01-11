#ifndef OUTPUTDEVICEFACTORYTEST_H_
#define OUTPUTDEVICEFACTORYTEST_H_

#include <gtest/gtest.h>
#include "OutputDeviceFactory.h"

class OutputDeviceFactoryTest : public ::testing::Test {
protected:
	void SetUp();
	void TearDown();

public:
	OutputDeviceFactoryTest();
	virtual ~OutputDeviceFactoryTest();

};

#endif
