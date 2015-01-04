/*
 * Copyright
 *
*/
#include "./Configurater.h"
#include <sstream>
#include <iostream>

Configurater::Configurater() : configFile_("/usr/local/etc/xfd.conf"),
    checkInterval_(0), baseUrl_("") {
  readConfigurationData();
}

Configurater::Configurater(std::string configFile) : configFile_(configFile),
    checkInterval_(0), baseUrl_("") {
  readConfigurationData();
}

Configurater::~Configurater() {
}

/////////////////////////////////////////////////////////////////////
void Configurater::readConfigurationData() {
  std::string readData;
  std::string key;
  std::string value;
  std::map<std::string, std::string> configData;
  fileDao_.openInputter(configFile_);

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

void Configurater::parseData(std::map<std::string, std::string> datas) {
  parseIntervalTime(datas);
  parseUrl(datas);
}

bool Configurater::isCommentLine(std::string dataString) {
  return dataString[0] == '#';
}

void Configurater::parseIntervalTime(
    std::map<std::string, std::string> configData) {
  std::istringstream iss(configData["interval"]);
  iss >> checkInterval_;
}

void Configurater::split(const std::string& str, char delimiter,
    std::string& key, std::string& value) {
  std::stringstream ss(str);

    getline(ss, key, delimiter);
    getline(ss, value, delimiter);
}

void Configurater::parseUrl(std::map<std::string, std::string> configData) {
  baseUrl_ = configData["url"];
}
