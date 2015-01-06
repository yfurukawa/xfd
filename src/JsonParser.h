/**
 * jsonParser.h<br>
 * Copyright
 *
 */

#ifndef JSONPARSER_H_
#define JSONPARSER_H_

#include <string>
#include <map>

class JsonParser {
public:
    //! Constractor
    JsonParser();
    //! Destructor
    virtual ~JsonParser();
    std::map<std::string, std::string> parse(const std::string jsonString);

protected:
private:
};

#endif  // JSONPARSER_H_
