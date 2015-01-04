#include <vector>
#include "ConfiguraterTest.h"

ConfiguraterTest::ConfiguraterTest() : sut(NULL) {

}

ConfiguraterTest::~ConfiguraterTest() {

}

void ConfiguraterTest::SetUp() {
}

void ConfiguraterTest::TearDown() {
	delete sut;
}

TEST_F (ConfiguraterTest, testGetCheckInterval_1) {
  sut = new Configurater("test.conf");
	EXPECT_EQ(1, sut->getCheckInterval());

}

TEST_F (ConfiguraterTest, testGetCheckInterval_10) {
  sut = new Configurater("test2.conf");
  EXPECT_EQ(10, sut->getCheckInterval());
}

TEST_F (ConfiguraterTest, testGetBaseURL) {
  sut = new Configurater("test.conf");
  EXPECT_EQ("http://server:8080/", sut->getBaseURL());
}

TEST_F (ConfiguraterTest, testGetNumberOfJobs) {
  sut = new Configurater("test.conf");
  EXPECT_EQ(2, sut->getNumberOfJobs());
}

TEST_F (ConfiguraterTest, testGetJobs) {
  sut = new Configurater("test.conf");
  std::vector<std::string> actualJobs = sut->getJobs();
  EXPECT_EQ("testJob1", actualJobs[0]);
  EXPECT_EQ("testJob2", actualJobs[1]);
}

