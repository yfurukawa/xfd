#include <vector>
#include <string>
#include "ConfiguratorTest.h"

ConfiguratorTest::ConfiguratorTest() : sut(NULL) {

}

ConfiguratorTest::~ConfiguratorTest() {

}

void ConfiguratorTest::SetUp() {
}

void ConfiguratorTest::TearDown() {
    delete sut;
}

TEST_F (ConfiguratorTest, testGetCheckInterval_1) {
    sut = new Configurator("test.conf");
    sut->readConfigurationData();
    EXPECT_EQ(1, sut->getCheckInterval());

}

TEST_F (ConfiguratorTest, testGetCheckInterval_10) {
    sut = new Configurator("test2.conf");
    sut->readConfigurationData();
    EXPECT_EQ(10, sut->getCheckInterval());
}

TEST_F (ConfiguratorTest, testGetBaseURL) {
    sut = new Configurator("test.conf");
    sut->readConfigurationData();
    EXPECT_EQ("localhost:8080", sut->getBaseURL());
}

TEST_F (ConfiguratorTest, getDeviceList_one_device) {
    std::string file("test2.conf");
    sut = new Configurator(file);
    sut->readConfigurationData();
    std::vector<std::string> list;
    list = sut->getDeviceList();
    EXPECT_EQ(1, list.size());
    EXPECT_EQ("gtk", list[0]);
}

TEST_F (ConfiguratorTest, getDeviceList_two_devices) {
    std::string file("test.conf");
    sut = new Configurator(file);
    sut->readConfigurationData();
    std::vector<std::string> list;
    list = sut->getDeviceList();
    EXPECT_EQ(2, list.size());
    EXPECT_EQ("gtk", list[0]);
    EXPECT_EQ("GPIO:21", list[1]);
}

TEST_F (ConfiguratorTest, testGetNumberOfJobs) {
    sut = new Configurator("test.conf");
    sut->readConfigurationData();
    EXPECT_EQ(2, sut->getJobs().size());
}

TEST_F (ConfiguratorTest, testGetJobs) {
    sut = new Configurator("test.conf");
    sut->readConfigurationData();
    std::vector<std::string> actualJobs = sut->getJobs();
    EXPECT_EQ("testJob1", actualJobs[0]);
    EXPECT_EQ("testJob2", actualJobs[1]);
}

TEST_F (ConfiguratorTest, catchExceptionWhenFileNotFound) {
    sut = new Configurator("notExistFile");

    EXPECT_THROW(sut->readConfigurationData(), std::string);
}

TEST_F (ConfiguratorTest, noException) {
    sut = new Configurator("test.conf");
    EXPECT_NO_THROW(sut->readConfigurationData());
}

TEST_F (ConfiguratorTest, getConfigFile) {
    std::string file("test.conf");
    sut = new Configurator(file);
    EXPECT_EQ(file, sut->getConfigFile());
}

TEST_F (ConfiguratorTest, getConfigFileWithFillPath) {
    std::string file("/etc/hosts");
    sut = new Configurator(file);
    EXPECT_EQ(file, sut->getConfigFile());
}
