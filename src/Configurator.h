/**
 * Configurater.h<br>
 * Copyright
 *
 */

#ifndef CONFIGURATOR_H_
#define CONFIGURATOR_H_

#include <string>
#include <map>
#include <vector>
#include "FileDAO.h"

class Configurator {
  private:
    FileDAO fileDao_;
    std::string configFile_;
    int checkInterval_;
    std::string baseUrl_;
    std::vector<std::string> jobs_;

  public:
    //! Constractor
    Configurator();
    Configurator(std::string configFile);
    //! Destructor
    virtual ~Configurator();
    int getCheckInterval() { return checkInterval_; };
    std::string getBaseURL() { return baseUrl_; };
    int getNumberOfJobs() { return jobs_.size(); };
    std::vector<std::string> getJobs() { return jobs_; };

  protected:
    void readConfigurationData();
    void parseData(std::map<std::string, std::string> datas);
    void split(const std::string &str, char delimiter, std::string& key, std::string& value);
    bool isCommentLine(std::string dataString);
    void parseIntervalTime(std::map<std::string, std::string> configData);
    void parseUrl(std::map<std::string, std::string> configData);
  private:
};

#endif  // CONFIGURATOR_H_
