#include "NetworkDAOTest.h"

NetworkDAOTest::NetworkDAOTest() {

}

NetworkDAOTest::~NetworkDAOTest() {

}

void NetworkDAOTest::SetUp() {
	sut = new NetworkDAOSpy();
}

void NetworkDAOTest::TearDown() {
	delete sut;
}

TEST_F (NetworkDAOTest, establishConnection) {
  sut->openInputter("localhost:8080");
  EXPECT_NE(0, sut->getSocket());
  sut->closeInputter();
}

TEST_F (NetworkDAOTest, testNameIsHere_ChangeThis) {
  sut->openInputter("localhost:8080");

  EXPECT_EQ("hoge", sut->readData());

  sut->closeInputter();
}
