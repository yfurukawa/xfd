/**
 * GpioOutputter.h<br>
 * Copyright
 *
 */

#ifndef GPIOOUTPUTTER_H_
#define GPIOOUTPUTTER_H_

#include <string>
#include "IOutputter.h"

class GpioOutputter : public IOutputter {
    public:
        //! コンストラクタ
        /**
         * \param name 出力ポート番号付のデバイス名 形式 GPIO:ポート番号
         */
        GpioOutputter(std::string name);

        //! デストラクタ
        virtual ~GpioOutputter();

        //! ジョブの結果を出力する
        /**
         * \param outputName 未使用
         * \param contents ジョブの結果（successまたはfail）
         */
        virtual void outputContents( std::string outputName, std::string contents );
    protected:

        //! GPIOを初期化する
        /**
         * GPIOを初期化する。デバイスの初期化に失敗した場合は例外をスローする。
         * \exception 初期化に失敗したデバイス
         */
        void initializeDevice(const std::string& name);
    private:
        //! コンストラクタ
        GpioOutputter() : portNumber_(5) {};
        int portNumber_;
};

#endif  // GPIOOUTPUTTER_H_
