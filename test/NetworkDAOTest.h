#ifndef NETWORKDAOTEST_H_
#define NETWORKDAOTEST_H_

#include <gtest/gtest.h>
#include "mocks/NetworkDAOSpy.h"

class NetworkDAOTest : public ::testing::Test {
protected:
	NetworkDAOSpy* sut;
	void SetUp();
	void TearDown();

public:
	NetworkDAOTest();
	virtual ~NetworkDAOTest();

};

#endif
