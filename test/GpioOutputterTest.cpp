#include "GpioOutputterTest.h"

GpioOutputterTest::GpioOutputterTest() {

}

GpioOutputterTest::~GpioOutputterTest() {

}

void GpioOutputterTest::SetUp() {
	sut = new GpioOutputter();
}

void GpioOutputterTest::TearDown() {
	delete sut;
}

TEST_F (GpioOutputterTest, testNameIsHere_ChangeThis) {
/* Write a test code here. */

}
