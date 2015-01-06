#include <string>
#include <map>
#include "JsonParserTest.h"

JsonParserTest::JsonParserTest() : sut(NULL) {

}

JsonParserTest::~JsonParserTest() {

}

void JsonParserTest::SetUp() {
	sut = new JsonParser();
}

void JsonParserTest::TearDown() {
	delete sut;
}

TEST_F (JsonParserTest, testParseSingleData) {
    std::map<std::string, std::string> parsedData;
    std::string jsonString("{'a':1}");

    parsedData = sut->parse(jsonString);
    EXPECT_EQ("a", parsedData.begin()->first);
    EXPECT_EQ("1", parsedData.begin()->second);
}

TEST_F (JsonParserTest, testParseMultipleDatas) {
    std::map<std::string, std::string> parsedData;
    std::string jsonString("{'test_integer' : 12345, 'test_double' : 987.654321,'test_string' : \"joys of programming\",'test_boolean' : true,'test_array' : [\"c\",\"c++\",\"d\",\"lisp\",],'test_object' : {'test_integer' : 54321,'test_double' : 123456.789,'test_string' : \"hello world\",'test_boolean' : false,'test_array' : [\"perl\",\"golang\",\"whitespace\",\"lua\",],},}");

    parsedData = sut->parse(jsonString);
    EXPECT_EQ("\"joys of programming\"", parsedData["test_string"]);
}

TEST_F (JsonParserTest, testParseJenkinsJson) {
    std::map<std::string, std::string> parsedData;
    std::string jsonString("{\"actions\":[{"
            "\"causes\":[{\"shortDescription\":\"Started by user anonymous\",\"userId\":null,\"userName\":\"anonymous\"}]},{\"failCount\":0,\"skipCount\":0,\"totalCount\":1,\"urlName\":\"testReport\"}],\"artifacts\":[],\"building\":false,\"description\":null,\"duration\":129,\"estimatedDuration\":1017,\"executor\":null,\"fullDisplayName\":\"testJob #2\",\"id\":\"2015-01-05_14-39-04\",\"keepLog\":false,\"number\":2,\"result\":\"SUCCESS\",\"timestamp\":1420436344000,\"url\":\"http://127.0.0.1:8080/job/testJob/2/\",\"builtOn\":\"\",\"changeSet\":{\"items\":[],\"kind\":null},\"culprits\":[]}");;

    parsedData = sut->parse(jsonString);
    EXPECT_EQ("\"SUCCESS\"", parsedData["result"]);
}
