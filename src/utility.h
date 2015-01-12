/*
 * utility.cpp
 *
 *  Created on: 2015/01/12
 *      Author: yoshi
 */

#ifndef UTILITY_HPP_
#define UTILITY_HPP_

#include <string>
#include <sstream>

namespace util {
void split(const std::string& baseString, char delimiter,
    std::string& lhs, std::string& rhs) {

    std::stringstream ss(baseString);

    getline(ss, lhs, delimiter);
    getline(ss, rhs, delimiter);
}

int stringToInt(std::string str) {
    int value;
    std::istringstream iss(str);
    iss >> value;
    return value;
}
}

#endif

