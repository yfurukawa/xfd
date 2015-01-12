/*
 * Copyright
 *
 */
#include "./Configurator.h"
#include <sstream>
#include <iostream>
#include <stdexcept>

Configurator::Configurator() : configFile_(""),
checkInterval_sec_(0), baseUrl_("") {
}

Configurator::Configurator(std::string configFile) : configFile_(configFile),
        checkInterval_sec_(0), baseUrl_("") {
}

Configurator::~Configurator() {
}

void Configurator::readConfigurationData() {
    std::string readData("");
    std::string key("");
    std::string value("");
    std::map<std::string, std::string> configData;
    try{
        fileDao_.openInputter(configFile_);
    }
    catch(const std::ios::failure& e) {
        std::string message("File Not Found");
        throw message;
    }
    catch(...) {
        std::string message("Unknown Exception");
        throw message;
    }

    do {
        try {
            readData = fileDao_.readData();
        }
        catch(const std::string& e) {
            throw;
        }
        catch(const std::ios::failure& e){
            break;
        }
        if(readData == "EOF") {
            break;
        }
        if(!isCommentLine(readData)){
            split(readData, '=', key, value);
            if(key == "job") {
                jobs_.push_back(value);
            }
            else if(key == "device") {
                outputter_.push_back(value);
            }
            else {
                configData[key] = value;
            }
        }
    }while(1);

    parseData(configData);

    fileDao_.closeInputter();
}

/////////////////////////////////////////////////////////////////////

void Configurator::parseData(std::map<std::string, std::string> datas) {
    parseIntervalTime(datas);
    parseUrl(datas);
}

bool Configurator::isCommentLine(std::string dataString) {
    return dataString[0] == '#';
}

void Configurator::parseIntervalTime(
        std::map<std::string, std::string> configData) {
    std::istringstream iss(configData["interval"]);
    iss >> checkInterval_sec_;
}

void Configurator::split(const std::string& str, char delimiter,
        std::string& key, std::string& value) {
    std::stringstream ss(str);

    getline(ss, key, delimiter);
    getline(ss, value, delimiter);
}

void Configurator::parseUrl(std::map<std::string, std::string> configData) {
    baseUrl_ = configData["url"];
}
