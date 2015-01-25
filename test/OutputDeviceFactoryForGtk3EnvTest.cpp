#include "OutputDeviceFactoryForGtk3EnvTest.h"

OutputDeviceFactoryForGtk3EnvTest::OutputDeviceFactoryForGtk3EnvTest() {

}

OutputDeviceFactoryForGtk3EnvTest::~OutputDeviceFactoryForGtk3EnvTest() {

}

void OutputDeviceFactoryForGtk3EnvTest::SetUp() {
	sut = new OutputDeviceFactoryForGtk3Env();
}

void OutputDeviceFactoryForGtk3EnvTest::TearDown() {
	delete sut;
}

TEST_F (OutputDeviceFactoryForGtk3EnvTest, testNameIsHere_ChangeThis) {
/* Write a test code here. */

}
