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

TEST_F (ConfiguratorTest, testGetNumberOfJobs) {
    sut = new Configurator("test.conf");
    sut->readConfigurationData();
    EXPECT_EQ(2, sut->getNumberOfJobs());
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
