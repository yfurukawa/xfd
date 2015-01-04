/**
 * FileDAOSpy.cpp
 *
 *  Created on: 2013/12/10
 *      Author: M825504
 */

#include "FileDAOSpy.h"

FileDAOSpy::FileDAOSpy(){
	// TODO 自動生成されたコンストラクター・スタブ

}

FileDAOSpy::~FileDAOSpy(){
	// TODO Auto-generated destructor stub
}

bool FileDAOSpy::isClosedInputStream(){
	return inputStream_.is_open();
}


