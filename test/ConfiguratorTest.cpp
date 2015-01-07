#include <vector>
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
	EXPECT_EQ(1, sut->getCheckInterval());

}

TEST_F (ConfiguratorTest, testGetCheckInterval_10) {
  sut = new Configurator("test2.conf");
  EXPECT_EQ(10, sut->getCheckInterval());
}

TEST_F (ConfiguratorTest, testGetBaseURL) {
  sut = new Configurator("test.conf");
  EXPECT_EQ("localhost:8080", sut->getBaseURL());
}

TEST_F (ConfiguratorTest, testGetNumberOfJobs) {
  sut = new Configurator("test.conf");
  EXPECT_EQ(2, sut->getNumberOfJobs());
}

TEST_F (ConfiguratorTest, testGetJobs) {
  sut = new Configurator("test.conf");
  std::vector<std::string> actualJobs = sut->getJobs();
  EXPECT_EQ("testJob1", actualJobs[0]);
  EXPECT_EQ("testJob2", actualJobs[1]);
}

