/**
 * IOutputter.h
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#ifndef IOUTPUTTER_H_
#define IOUTPUTTER_H_

#include <string>

class IOutputter {
public:
	IOutputter();
	virtual ~IOutputter();
	virtual void outputContents( std::string outputName, std::string contents ) = 0;
};

#endif /* IOUTPUTTER_H_ */
