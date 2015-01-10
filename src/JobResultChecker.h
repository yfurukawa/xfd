/**
 * JobResultChecker.h<br>
 * Copyright
 *
 */

#ifndef JOBRESULTCHECKER_H_
#define JOBRESULTCHECKER_H_

#include <string>
#include "JsonParser.h"

class NetworkDAO;

class JobResultChecker {
    protected:
        const std::string jobName_;
        NetworkDAO* networkDao_;
        JsonParser parser;

        void sendRequestMessageToJenkins();
        bool judgeJenkinsJobResult();
        bool isJsonString(std::string readData);

    public:
       //! Constractor
       explicit JobResultChecker(const std::string jobName, NetworkDAO* networkDao);
       //! Destructor
       virtual ~JobResultChecker();
       std::string getJobName();
       bool checkResult();
    protected:
    private:
        JobResultChecker();
};

#endif  // JOBRESULTCHECKER_H_
