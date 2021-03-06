/**
 * Conductor.h<br>
 * Configuratorクラスから設定情報を貰い、各クラスに指示を出す
 *
 * Configratorクラスから監視周期、jenkinsサーバのURL及び監視対象ジョブ名
 * を貰い、必要なクラスを生成し指示を出す。
 *
 * Copyright Yoshihiro Furukawa
 *
 */

#ifndef CONDUCTOR_H_
#define CONDUCTOR_H_

#include <string>
#include <vector>
#include <pthread.h>
#include "IOutputter.h"

class JobResultChecker;
class Configurator;

class Conductor {

public:
    //! コンストラクタ
    Conductor();
    Conductor(const std::string& configFile);
    //! デストラクタ
    virtual ~Conductor();
    //! 監視を実行する
    void execute(int* argc, char*** argv);
    //!

protected:
    //! 設定を読み込む
    void initializeConfiguration();
    //! 各ジョブの実行結果を集計する
    bool tallyJobResult();
    //! 出力デバイスを初期化する
    void initializeOutputDevice();

    Configurator* configurator_; //!< Configuratorクラス
    int checkInterval_; //!< 監視周期[秒]
    std::string baseUrl_; //!< jenkinsのurl
    std::vector<std::string> jobs_; //!< ジョブ名のリスト
    std::vector<JobResultChecker*> resultChecker_; //!< 各ジョブの実行結果監視クラスのリスト
    int bufferLength_byte_; //!< ネットワークの受信バッファのサイズ
    std::string configFile_; //!< コンフィグレーションファイル名
    std::vector<std::string> outputDeviceList_; //!< 出力デバイスのリスト
    std::vector<IOutputter*> outputter_;  //!< 出力デバイス

};

#endif  // CONDUCTOR_H_
