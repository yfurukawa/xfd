#include <string>
#include <vector>
#include "OutputDeviceFactoryTest.h"
#include "IOutputter.h"

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

TEST_F (OutputDeviceFactoryTest, setCommandLineArguments) {
    OutputDeviceFactory& sut = OutputDeviceFactory::getInstance();
    int argc;
    char** argv;
    sut.setCommandLineArguments(&argc, &argv);
}

TEST_F (OutputDeviceFactoryTest, createOutputterInstance_gtk) {
    OutputDeviceFactory& sut = OutputDeviceFactory::getInstance();
    int argc;
    char** argv;
    sut.setCommandLineArguments(&argc, &argv);

    std::vector<std::string> deviceList;
    deviceList.push_back("gtk");
    std::vector<IOutputter*> outputter;
    outputter = sut.getOutputterList(deviceList);
    EXPECT_EQ("gtk", (*outputter.begin())->getDeviceName());
}

TEST_F (OutputDeviceFactoryTest, createOutputterInstance_gpio) {
    OutputDeviceFactory& sut = OutputDeviceFactory::getInstance();
    int argc;
    char** argv;
    sut.setCommandLineArguments(&argc, &argv);

    std::vector<std::string> deviceList;
    deviceList.push_back("GPIO:21");
    std::vector<IOutputter*> outputter;
    outputter = sut.getOutputterList(deviceList);
    EXPECT_EQ("GPIO:21", (*outputter.begin())->getDeviceName());
}
