#include "Gtk2OutputterTest.h"

Gtk2OutputterTest::Gtk2OutputterTest() {

}

Gtk2OutputterTest::~Gtk2OutputterTest() {

}

void Gtk2OutputterTest::SetUp() {
	sut = new Gtk2Outputter();
}

void Gtk2OutputterTest::TearDown() {
	delete sut;
}

TEST_F (Gtk2OutputterTest, testNameIsHere_ChangeThis) {
/* Write a test code here. */

}
