#include "ConductorTest.h"

ConductorTest::ConductorTest() : sut(NULL) {

}

ConductorTest::~ConductorTest() {

}

void ConductorTest::SetUp() {
	sut = new ConductorSpy();
}

void ConductorTest::TearDown() {
	delete sut;
}

