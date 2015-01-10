/*
 * Copyright
 *
*/
#include "./Configurator.h"
#include <sstream>
#include <iostream>

Configurator::Configurator() : configFile_(""),
    checkInterval_(0), baseUrl_("") {
}

Configurator::Configurator(std::string configFile) : configFile_(configFile),
    checkInterval_(0), baseUrl_("") {
}

Configurator::~Configurator() {
}

/////////////////////////////////////////////////////////////////////
void Configurator::readConfigurationData() {
  std::string readData;
  std::string key;
  std::string value;
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
    readData = fileDao_.readData();
    if(readData == "EOF") {
      break;
    }
    if(!isCommentLine(readData)){
      split(readData, '=', key, value);
      if(key != "job") {
        configData[key] = value;
      }
      else {
        jobs_.push_back(value);
      }
    }
  }while(1);

  parseData(configData);

  fileDao_.closeInputter();
}

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
  iss >> checkInterval_;
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
