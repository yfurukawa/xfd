/**
 * FileDAO.h<br>
 * ファイルの読み書きをする
 *
 * 引数で指定されたファイルからテキストを1行ずつ読み込んだり、
 * 引数で指定されたファイルへテキストを書き込んだりする。
 *
 *  Created on: 2013/08/14<br>
 *      Author: furukawayoshihiro
 */

#ifndef FILEDAO_H_
#define FILEDAO_H_

#include <fstream>
#include <iostream>

#include "IOutputter.h"
#include "IInputter.h"

class FileDAO: public IOutputter, public IInputter {
public:
	//! コンストラクタ
	FileDAO();
	//! デストラクタ
	virtual ~FileDAO();
	//! 引数で渡されたコンテンツをファイルへ書き出す
	/*!
	 * \param outputName 書き出し先のファイル名
	 * \param contents 書き出す内容
	 */
	virtual void outputContents( std::string outputName, std::string contents );
	//! 読み込みファイルをオープンする
	/*!
	 * \param name オープンするファイル名
	 */
	virtual void openInputter( std::string name );
	//! オープンしていたファイルをクローズする
	/*!
	 * ファイルが既にクローズされていた場合は、例外を生成する
	 * \exception std::string クローズ済みのメッセージ
	 */
	virtual void closeInputter();
	//! ファイルから1行読み込む
	/*!
	 * ファイルがオープンされる前に読み込むと例外を生成する
	 *
	 * \return ファイルから読み込んだ文字列
	 * \exception std::string クローズ済みのメッセージ
	 */
	virtual std::string readData();
	//! 指定されたファイルの有無を確認する
	/*!
	 * \param name 有無を確認するファイル名
	 */
	virtual bool isExsist( std::string name );
protected:
	std::ifstream inputStream_; //!< 入力ファイルストリーム
};

#endif /* FILEDAO_H_ */
