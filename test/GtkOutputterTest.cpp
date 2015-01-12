#include "GtkOutputterTest.h"

GtkOutputterTest::GtkOutputterTest() {

}

GtkOutputterTest::~GtkOutputterTest() {

}

void GtkOutputterTest::SetUp() {
	sut = new GtkOutputter();
}

void GtkOutputterTest::TearDown() {
	delete sut;
}

TEST_F (GtkOutputterTest, testNameIsHere_ChangeThis) {
/* Write a test code here. */

}
