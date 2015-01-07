#ifndef CONFIGURATORTEST_H_
#define CONFIGURATORTEST_H_

#include <gtest/gtest.h>
#include "Configurator.h"

class ConfiguratorTest : public ::testing::Test {
protected:
	Configurator* sut;
	void SetUp();
	void TearDown();

public:
	ConfiguratorTest();
	virtual ~ConfiguratorTest();

};

#endif
