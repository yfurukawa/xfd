#ifndef JSONPARSERTEST_H_
#define JSONPARSERTEST_H_

#include <gtest/gtest.h>
#include "JsonParser.h"

class JsonParserTest : public ::testing::Test {
protected:
	JsonParser* sut;
	void SetUp();
	void TearDown();

public:
	JsonParserTest();
	virtual ~JsonParserTest();

};

#endif
