#ifndef CONFIGURATERTEST_H_
#define CONFIGURATERTEST_H_

#include <gtest/gtest.h>
#include "Configurater.h"

class ConfiguraterTest : public ::testing::Test {
protected:
	Configurater* sut;
	void SetUp();
	void TearDown();

public:
	ConfiguraterTest();
	virtual ~ConfiguraterTest();

};

#endif
