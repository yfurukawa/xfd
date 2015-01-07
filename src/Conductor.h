/**
 * Conductor.h<br>
 * Copyright
 *
 */

#ifndef CONDUCTOR_H_
#define CONDUCTOR_H_

#include <string>
#include <vector>
#include "Configurator.h"

class JobResultChecker;

class Conductor {
protected:
    Configurator configurator_;
    int checkInterval_;
    std::string baseUrl_;
    std::vector<std::string> jobs_;
    std::vector<JobResultChecker*> resultChecker_;

    void initializeConfiguration();
public:
    //! Constractor
    Conductor();
    //! Destructor
    virtual ~Conductor();

protected:

private:
};

#endif  // CONDUCTOR_H_
