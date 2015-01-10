/*
 * Copyright
 *
*/

#include "./JsonParser.h"

JsonParser::JsonParser() {
}

JsonParser::~JsonParser() {
}

std::map<std::string, std::string> JsonParser::parse(const std::string jsonString) {
    std::map<std::string, std::string> parsedData;

    struct json_object* jsonObjectFromString = json_tokener_parse(jsonString.c_str());
    json_object_object_foreach(jsonObjectFromString, key, value) {
        parsedData[key] = json_object_to_json_string(value);
    }

    return parsedData;
}
