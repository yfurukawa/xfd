#include "NetworkDAOTest.h"

NetworkDAOTest::NetworkDAOTest() : sut(NULL) {

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
  sut->openInputter("127.0.0.1:8080");
  sut->sendRequest("GET /job/testJob/lastBuild/api/json\r\n\r\n");
  EXPECT_EQ("hoge", sut->readData());

  sut->closeInputter();
}
