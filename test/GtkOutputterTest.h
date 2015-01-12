#ifndef GTKOUTPUTTERTEST_H_
#define GTKOUTPUTTERTEST_H_

#include <gtest/gtest.h>
#include "GtkOutputter.h"

class GtkOutputterTest : public ::testing::Test {
protected:
	GtkOutputter* sut;
	void SetUp();
	void TearDown();

public:
	GtkOutputterTest();
	virtual ~GtkOutputterTest();

};

#endif
