/**
 * FileOutputterDAO.cpp
 *
 *  Created on: 2013/08/14
 *      Author: furukawayoshihiro
 */

#include <iostream>
#include <fstream>

#include "FileDAOTest.h"

FileDAOTest::FileDAOTest() : sut(NULL) {
}

FileDAOTest::~FileDAOTest() {
	// TODO Auto-generated destructor stub
}

void FileDAOTest::SetUp() {
	sut = new FileDAOSpy();
}

void FileDAOTest::TearDown() {
	delete sut;
}

TEST_F(FileDAOTest, createFile_Hoge) {
	sut->outputContents("Hoge.cpp", "");

	std::ifstream in("Hoge.cpp");
	EXPECT_TRUE(in != NULL);
}

TEST_F(FileDAOTest, createFile_Fuga) {
	sut->outputContents("Fuga.cpp", "");

	std::ifstream in("Fuga.cpp");
	EXPECT_TRUE(in != NULL);
}

TEST_F(FileDAOTest, contents_foobar) {
	sut->outputContents("Hoge.cpp", "foo\nbar");

	std::ifstream in("Hoge.cpp");
	std::string contents;
	in >> contents;
	EXPECT_EQ("foo", contents);
	in >> contents;
	EXPECT_EQ("bar", contents);
}

TEST_F(FileDAOTest, catchExceptionWhenOpenFileInputDueToFileNOTExsist) {
	EXPECT_THROW( sut->openInputter("NotExsitFile"), std::ios::failure);
}

TEST_F(FileDAOTest, notCatchExceptionWhenOpenFileDueToInputFileExsist) {
	EXPECT_NO_THROW( sut->openInputter("FileDAO.cpp") );
}

TEST_F(FileDAOTest, getTrueWhenTargetFileExsist) {
	EXPECT_TRUE(sut->isExsist("FileDAO.cpp"));
	EXPECT_FALSE(sut->isClosedInputStream());
}

TEST_F(FileDAOTest, getFalseWhenTargetFileIsNOTExsist) {
	EXPECT_FALSE(sut->isExsist("NoExsistFile"));
	EXPECT_FALSE(sut->isClosedInputStream());
}

TEST_F(FileDAOTest, catchExceptionWhenReadDataDueToFileIsNOTOpen) {
	EXPECT_THROW( sut->readData(), std::string);
}

TEST_F(FileDAOTest, notCatchExceptionWhenReadDataDueToFileIsOpened) {
	sut->openInputter("FileDAO.cpp");
	EXPECT_NO_THROW( sut->readData());
}

TEST_F(FileDAOTest, readData) {
	std::string testFile("test.txt");
	std::string testString("Test String.");
	prepareTestingFile(testFile, testString);

	sut->openInputter(testFile);
	try {
		EXPECT_EQ(testString, sut->readData());
	}
	catch(const std::ios::failure& e) {
		std::cout << e.what() << std::endl;
		FAIL();
	}
	catch(const std::string& e) {
		std::cout << e << std::endl;
		FAIL();
	}
}

TEST_F(FileDAOTest, readData_MultiLines) {
	std::string testFile("test.txt");
	std::string testString1stLine("1st Line");
	std::string testString2ndLine("2nd Line");
	prepareTestingFile(testFile, testString1stLine+"\n"+testString2ndLine);

	sut->openInputter(testFile);
	try {
		EXPECT_EQ(testString1stLine, sut->readData());
		EXPECT_EQ(testString2ndLine, sut->readData());
	}
	catch(const std::ios::failure& e) {
		std::cout << e.what() << std::endl;
		FAIL();
	}
	catch(const std::string& e) {
		std::cout << e << std::endl;
		FAIL();
	}
}

TEST_F(FileDAOTest, catchExceptionWhenCloseFileDueToFileHandlerWasClosed) {
	EXPECT_THROW( sut->closeInputter(), std::string);
}

TEST_F(FileDAOTest, notCatchExceptionWhenCloseFile) {
	sut->openInputter("FileDAO.cpp");
	EXPECT_NO_THROW( sut->closeInputter());
}


/////////////////////////////////////////////////////////////
void FileDAOTest::prepareTestingFile(std::string fileName,
		std::string contents) {
	std::ofstream ofs(fileName.c_str());
	ofs << contents << std::endl;
}
