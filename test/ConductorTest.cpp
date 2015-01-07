#include "ConductorTest.h"

ConductorTest::ConductorTest() {

}

ConductorTest::~ConductorTest() {

}

void ConductorTest::SetUp() {
	sut = new Conductor();
}

void ConductorTest::TearDown() {
	delete sut;
}

TEST_F (ConductorTest, testNameIsHere_ChangeThis) {
/* Write a test code here. */

}
