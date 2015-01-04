#include "NetworkDAOTest.h"

NetworkDAOTest::NetworkDAOTest() {

}

NetworkDAOTest::~NetworkDAOTest() {

}

void NetworkDAOTest::SetUp() {
	sut = new NetworkDAO();
}

void NetworkDAOTest::TearDown() {
	delete sut;
}

TEST_F (NetworkDAOTest, testNameIsHere_ChangeThis) {
/* Write a test code here. */

}
