#include "JobResultCheckerTest.h"

JobResultCheckerTest::JobResultCheckerTest() {

}

JobResultCheckerTest::~JobResultCheckerTest() {

}

void JobResultCheckerTest::SetUp() {
	sut = new JobResultChecker();
}

void JobResultCheckerTest::TearDown() {
	delete sut;
}

TEST_F (JobResultCheckerTest, testNameIsHere_ChangeThis) {
/* Write a test code here. */

}
