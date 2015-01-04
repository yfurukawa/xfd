/**
 * FileDAOSpy.h
 *
 *  Created on: 2013/12/10
 *      Author: M825504
 */

#ifndef FILEDAOSPY_H_
#define FILEDAOSPY_H_

#include "FileDAO.h"

class FileDAOSpy : public FileDAO {
public:
	FileDAOSpy();
	virtual ~FileDAOSpy();
	bool isClosedInputStream();
};

#endif /* FILEDAOSPY_H_ */
