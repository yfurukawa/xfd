#ifndef NETWORKDAOTEST_H_
#define NETWORKDAOTEST_H_

#include <gtest/gtest.h>
#include "NetworkDAO.h"

class NetworkDAOTest : public ::testing::Test {
protected:
	NetworkDAO* sut;
	void SetUp();
	void TearDown();

public:
	NetworkDAOTest();
	virtual ~NetworkDAOTest();

};

#endif
