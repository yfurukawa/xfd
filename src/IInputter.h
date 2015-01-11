/**
 * IInputter.h<br>
 * 入力デバイス用インターフェース
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

	//! 入力デバイスをオープンする
	/**
	 * \param name オープンするファイルだったり、接続先のサーバだったり
	 */
	virtual void openInputter( std::string name ) = 0;

	//! 入力デバイスをクローズする
	virtual void closeInputter() = 0;

	//! 入力デバイスから１行読み込む
	virtual std::string readData() = 0;

	//! 入力元が存在するか確認する
	/**
	 * \param[in] name オープンするファイルだったり、接続先のサーバだったり
	 */
	virtual bool isExsist ( std::string name ) = 0;
};

#endif /* IINPUTTER_H_ */
