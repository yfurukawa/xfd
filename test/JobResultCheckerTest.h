#ifndef JOBRESULTCHECKERTEST_H_
#define JOBRESULTCHECKERTEST_H_

#include <gtest/gtest.h>
#include "JobResultChecker.h"

class JobResultCheckerTest : public ::testing::Test {
protected:
	JobResultChecker* sut;
	void SetUp();
	void TearDown();

public:
	JobResultCheckerTest();
	virtual ~JobResultCheckerTest();

};

#endif
