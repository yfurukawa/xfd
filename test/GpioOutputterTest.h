#ifndef GPIOOUTPUTTERTEST_H_
#define GPIOOUTPUTTERTEST_H_

#include <gtest/gtest.h>
#include "GpioOutputter.h"

class GpioOutputterTest : public ::testing::Test {
protected:
	GpioOutputter* sut;
	void SetUp();
	void TearDown();

public:
	GpioOutputterTest();
	virtual ~GpioOutputterTest();

};

#endif
