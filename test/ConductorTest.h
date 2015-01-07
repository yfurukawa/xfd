#ifndef CONDUCTORTEST_H_
#define CONDUCTORTEST_H_

#include <gtest/gtest.h>
#include "mocks/ConductorSpy.h"

class ConductorTest : public ::testing::Test {
protected:
	ConductorSpy* sut;
	void SetUp();
	void TearDown();

public:
	ConductorTest();
	virtual ~ConductorTest();

};

#endif
