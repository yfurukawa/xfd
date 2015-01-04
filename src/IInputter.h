/**
 * IInputter.h
 *
 *  Created on: 2013/11/28
 *      Author: M825504
 */

#ifndef IINPUTTER_H_
#define IINPUTTER_H_

#include <string>

class IInputter {
public:
	IInputter(){};
	virtual ~IInputter(){};
	virtual void openInputter( std::string name ) = 0;
	virtual void closeInputter() = 0;
	virtual std::string readData() = 0;
	virtual bool isExsist ( std::string name ) = 0;
};

#endif /* IINPUTTER_H_ */
