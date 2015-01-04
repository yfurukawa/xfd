/**
 * FileDAO.cpp
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */


#include "FileDAO.h"

FileDAO::FileDAO() {

}

FileDAO::~FileDAO() {
	// TODO Auto-generated destructor stub
}

void FileDAO::outputContents(std::string outputName, std::string contents) {
	std::ofstream outFile(outputName.c_str(), std::ios::out | std::ios::trunc);

	outFile << contents;
}

void FileDAO::openInputter( std::string name ) {
	inputStream_.exceptions( std::ios::failbit | std::ios::badbit);
	inputStream_.open(name.c_str(), std::ios::in );
}

void FileDAO::closeInputter(){
	if(inputStream_.is_open()) {
		inputStream_.close();
	}
	else {
		std::string exceptionMessage("File Handler is already closed.");
		throw exceptionMessage;
	}
}

bool FileDAO::isExsist( std::string name ){
	try {
		this->openInputter( name );
		inputStream_.close();
		return true;
	}
	catch (...) {
		return false;
	}
	return false;
}

std::string FileDAO::readData(){
	if(inputStream_.is_open()) {
		std::string readData;
		if(!inputStream_.eof()){
		  getline(inputStream_, readData);
		  return readData;
		}
		else {
		  return "";
		}
	}
	else {
		std::string exceptionMessage("File is not opened.");
		throw exceptionMessage;
		return "";
	}
}

