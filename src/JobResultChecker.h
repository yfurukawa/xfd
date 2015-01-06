/**
 * JobResultChecker.h<br>
 * Copyright
 *
 */

#ifndef JOBRESULTCHECKER_H_
#define JOBRESULTCHECKER_H_

#include <string>

class JobResultChecker {
    protected:
        std::string jobName_;
    public:
       //! Constractor
       explicit JobResultChecker(const std::string jobName);
       //! Destructor
       virtual ~JobResultChecker();
       std::string getJobName();
       bool checkResult();
    protected:
    private:
        JobResultChecker();
};

#endif  // JOBRESULTCHECKER_H_
