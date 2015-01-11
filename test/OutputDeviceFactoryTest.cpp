#include "OutputDeviceFactoryTest.h"

OutputDeviceFactoryTest::OutputDeviceFactoryTest() {

}

OutputDeviceFactoryTest::~OutputDeviceFactoryTest() {

}

void OutputDeviceFactoryTest::SetUp() {
}

void OutputDeviceFactoryTest::TearDown() {
}

TEST_F (OutputDeviceFactoryTest, createInstance) {
    OutputDeviceFactory& sut = OutputDeviceFactory::getInstance();
    EXPECT_EQ(typeid(OutputDeviceFactory), typeid(sut));
}
