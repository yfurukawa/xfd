#include <string>
#include "JobResultCheckerTest.h"
#include "mocks/NetworkDAOMock.h"

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
    sut = new JobResultChecker(expectResult, NULL);
    EXPECT_EQ(expectResult, sut->getJobName());
}

TEST_F (JobResultCheckerTest, testGetJobName_testJob2) {
    std::string expectResult("testJob2");
    sut = new JobResultChecker(expectResult, NULL);
    EXPECT_EQ(expectResult, sut->getJobName());
}

TEST_F (JobResultCheckerTest, testSentRequest) {
    NetworkDAOMock* daoMock(new NetworkDAOMock());
    std::string jobName("testJob");
    sut = new JobResultChecker(jobName, daoMock);
    sut->checkResult();

    EXPECT_EQ("GET /job/testJob/lastBuild/api/json\r\n\r\n", daoMock->getRequestedMessage());
    delete daoMock;
}

TEST_F (JobResultCheckerTest, testCheckResult_true) {
    NetworkDAOMock* daoMock(new NetworkDAOMock());
    std::string jobName("testJob");
    sut = new JobResultChecker(jobName, daoMock);

    EXPECT_EQ(true, sut->checkResult());
    delete daoMock;
}

TEST_F (JobResultCheckerTest, testCheckResult_false) {
    NetworkDAOMock* daoMock(new NetworkDAOMock());
    daoMock->setResult(false);
    std::string jobName("testJob");
    sut = new JobResultChecker(jobName, daoMock);

    EXPECT_EQ(false, sut->checkResult());
    delete daoMock;
}
