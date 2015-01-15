/**
 * GpioOutputter.h<br>
 * Copyright
 *
 */

#ifndef GPIOOUTPUTTER_H_
#define GPIOOUTPUTTER_H_

#include <string>
#include "IOutputter.h"

enum status {SUCCESS, FAIL};

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

        //! 出力デバイス名を返す
        /*!
         * \return 出力デバイス名
         */
        virtual std::string getDeviceName() { return deviceName_; };

        //! GPIOを初期化する
        /**
         * GPIOを初期化する。デバイスの初期化に失敗した場合は例外をスローする。
         * \exception 初期化に失敗したデバイス
         */
        virtual void initializeDevice();

    protected:

        //! マルチスレッド用呼出メソッド
        static void* run(void* pParameter);

    private:
        //! コンストラクタ
        GpioOutputter() : deviceName_("GPIO") {};
        static int portNumber_;  //!< 出力用GPIOポート番号
        std::string deviceName_; //!< デバイス名
        static bool isFailConditionContinue_;  //!< 失敗状態が継続している事を示すフラグ

        static enum status status_;
};

#endif  // GPIOOUTPUTTER_H_
