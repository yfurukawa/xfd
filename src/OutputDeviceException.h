/**
 * OutputDeviceException.h<br>
 * Copyright
 *
 */

#ifndef OUTPUTDEVICEEXCEPTION_H_
#define OUTPUTDEVICEEXCEPTION_H_

#include <bits/ios_base.h>
#include <string>

class OutputDeviceException : public std::ios_base::failure {
    public:
        //! Constractor
        OutputDeviceException(const std::string& cause)
            : std::ios_base::failure("cause : " + cause) {}
};

#endif  // OUTPUTDEVICEEXCEPTION_H_
