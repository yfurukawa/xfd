#include <string>
#include "JobResultCheckerTest.h"

JobResultCheckerTest::JobResultCheckerTest() : sut(NULL) {

}

JobResultCheckerTest::~JobResultCheckerTest() {

}

void JobResultCheckerTest::SetUp() {
}

void JobResultCheckerTest::TearDown() {
	delete sut;
}

TEST_F (JobResultCheckerTest, testGetJobName_testJob) {
    std::string expectResult("testJob");
    sut = new JobResultChecker(expectResult);
    EXPECT_EQ(expectResult, sut->getJobName());
}

TEST_F (JobResultCheckerTest, testGetJobName_testJob2) {
    std::string expectResult("testJob2");
    sut = new JobResultChecker(expectResult);
    EXPECT_EQ(expectResult, sut->getJobName());
}
