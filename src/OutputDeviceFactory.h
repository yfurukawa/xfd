/**
 * OutputDeviceFactory.h<br>
 * Copyright
 *
 */

#ifndef OUTPUTDEVICEFACTORY_H_
#define OUTPUTDEVICEFACTORY_H_

#include <iostream>
#include <vector>
#include "IOutputter.h"

class OutputDeviceFactory {
    public:
        //! デストラクタ
        virtual ~OutputDeviceFactory();

        //! シングルトンにするためのインスタンス生成用メソッド
        static OutputDeviceFactory& getInstance();

        //! GTK出力用クラスの生成に必要なコマンドライン引数をセットする
        /*!
         * \param[in] argc コマンドライン引数
         * \param[in] argv コマンドライン引数
         */
        void setCommandLineArguments(int* argc, char*** argv);

        //! 生成した出力デバイスのインスタンスリストを返す
        /*!
         * \return インスタンスリスト
         */
        std::vector<IOutputter*> getOutputterList(std::vector<std::string> deviceType);
    private:
        //! コンストラクタ
        OutputDeviceFactory() : argc_(NULL), argv_(NULL) {}
        OutputDeviceFactory(const OutputDeviceFactory& own) : argc_(NULL), argv_(NULL) {}

        int* argc_; //!< コマンドライン引数
        char*** argv_; //!< コマンドライン引数

};

#endif  // OUTPUTDEVICEFACTORY_H_
