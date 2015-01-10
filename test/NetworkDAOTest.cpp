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
  std::string expectString("{\"actions\":[{\"causes\":[{\"shortDescription\":\"\xE3\x83\xA6\xE3\x83\xBC\xE3\x82\xB6\xE3\x83\xBC" "anonymous\xE3\x81\x8C\xE5\xAE\x9F\xE8\xA1\x8C\",\"userId\":null,\"userName\":\"anonymous\"}]},{\"failCount\":0,\"skipCount\":0,\"totalCount\":1,\"urlName\":\"testReport\"}],\"artifacts\":[],\"building\":false,\"description\":null,\"duration\":1287,\"estimatedDuration\":841,\"executor\":null,\"fullDisplayName\":\"testJob #2\",\"id\":\"2015-01-04_21-33-04\",\"keepLog\":false,\"number\":2,\"result\":\"SUCCESS\",\"timestamp\":1420374784000,\"url\":\"http://127.0.0.1:8080/job/testJob/2/\",\"builtOn\":\"\",\"changeSet\":{\"items\":[],\"kind\":null},\"culprits\":[]}");
  sut->openInputter("127.0.0.1:8080");
  sut->sendRequest("GET /job/testJob/lastBuild/api/json\r\n\r\n");
  EXPECT_EQ(expectString, sut->readData());

  sut->closeInputter();
}
