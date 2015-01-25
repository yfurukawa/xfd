#ifndef GTK2OUTPUTTERTEST_H_
#define GTK2OUTPUTTERTEST_H_

#include <gtest/gtest.h>
#include "Gtk2Outputter.h"

class Gtk2OutputterTest : public ::testing::Test {
protected:
	Gtk2Outputter* sut;
	void SetUp();
	void TearDown();

public:
	Gtk2OutputterTest();
	virtual ~Gtk2OutputterTest();

};

#endif
