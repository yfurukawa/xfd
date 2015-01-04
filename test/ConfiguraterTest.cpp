#include "ConfiguraterTest.h"

ConfiguraterTest::ConfiguraterTest() {

}

ConfiguraterTest::~ConfiguraterTest() {

}

void ConfiguraterTest::SetUp() {
	sut = new Configurater();
}

void ConfiguraterTest::TearDown() {
	delete sut;
}

TEST_F (ConfiguraterTest, testNameIsHere_ChangeThis) {
/* Write a test code here. */

}
