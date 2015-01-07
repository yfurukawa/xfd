#ifndef CONDUCTORTEST_H_
#define CONDUCTORTEST_H_

#include <gtest/gtest.h>
#include "Conductor.h"

class ConductorTest : public ::testing::Test {
protected:
	Conductor* sut;
	void SetUp();
	void TearDown();

public:
	ConductorTest();
	virtual ~ConductorTest();

};

#endif
