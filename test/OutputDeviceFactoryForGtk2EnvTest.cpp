#include "OutputDeviceFactoryForGtk2EnvTest.h"

OutputDeviceFactoryForGtk2EnvTest::OutputDeviceFactoryForGtk2EnvTest() {

}

OutputDeviceFactoryForGtk2EnvTest::~OutputDeviceFactoryForGtk2EnvTest() {

}

void OutputDeviceFactoryForGtk2EnvTest::SetUp() {
	sut = new OutputDeviceFactoryForGtk2Env();
}

void OutputDeviceFactoryForGtk2EnvTest::TearDown() {
	delete sut;
}

TEST_F (OutputDeviceFactoryForGtk2EnvTest, testNameIsHere_ChangeThis) {
/* Write a test code here. */

}
