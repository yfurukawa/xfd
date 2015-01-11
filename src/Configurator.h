/**
 * Configurater.h<br>
 * コンフィグレーションファイルから設定値を読み込む
 *
 * コンフィグレーションファイルから設定を読み込み、設定キーと値にパースする
 * Copyright Yoshihiro Furukawa
 *
 */

#ifndef CONFIGURATOR_H_
#define CONFIGURATOR_H_

#include <string>
#include <map>
#include <vector>
#include "FileDAO.h"

class Configurator {
    public:
        //! コンストラクタ
        /*!
        * \param[in] configFile コンフィグレーションファイル名（/path/to/file）
         */
        Configurator(std::string configFile);

        //! デストラクタ
        virtual ~Configurator();

        //! コンフィグレーションファイルから設定データを読み込む
         /*!
          * コンフィグレーションファイルから設定データを読み込む際に
          * 問題があれば例外をスローする。<br>
          * \exception std::string File Not Foundメッセージ
          * \exception std::string File is not openedメッセージ
          */
        void readConfigurationData();

        //! 監視間隔を返す
        /*!
         * \return 監視間隔[秒]
         */
        int getCheckInterval() { return checkInterval_; };

        //! jenkinsのアドレスを返す
        /*!
         * \return アドレス（ホスト名：ポート番号）
         */
        std::string getBaseURL() { return baseUrl_; };

        //! jenkinsのジョブリストを返す
        /*!
         * \return ジョブリスト
         */
        std::vector<std::string> getJobs() { return jobs_; };

        //! 現在のコンフィグレーションファイルのファイル名を返す
        /*!
         * \return コンフィグレーションファイル名
         */
        std::string getConfigFile() { return configFile_; };

    protected:
        //! 設定データのパーサーを呼び出す移譲メソッド
        /*!
         * \param[in] datas 設定データのキーと値のペア
         */
        void parseData(std::map<std::string, std::string> datas);

        //! 設定データをキーと値のペアに分割する
        /*!
         * \param[in] str 設定データ
         * \param[in] delimiter 設定データ分割文字
         * \param[out] key 設定データの種類
         * \param[out] value 設定値
         */
        void split(const std::string &str, char delimiter, std::string& key, std::string& value);

        //! ファイルから読み込んだ行がコメント行か否かを判定する
        /*!
         * \param[in] dataString 読み込んだ行
         * \return 判定結果（true：コメント行）
         */
        bool isCommentLine(std::string dataString);

        //! 設定値のペアから監視間隔を見つけ保存する
        /*!
         * \param[in] configData 設定データのキーと値のペア
         */
        void parseIntervalTime(std::map<std::string, std::string> configData);

        //! 設定値のペアからjenkinsのアドレスを見つけ保存する
        /*!
         * \param[in] configData 設定データのキーと値のペア
         */
        void parseUrl(std::map<std::string, std::string> configData);

    private:
        //! コンストラクタ
        Configurator();
        FileDAO fileDao_; //!< ファイルアクセスクラス
        std::string configFile_; //!< コンフィグレーションファイル名
        int checkInterval_; //!< 監視間隔[秒]
        std::string baseUrl_; //!< jenkinsのアドレス
        std::vector<std::string> jobs_; //!< jenkinsのジョブ名のリスト
};

#endif  // CONFIGURATOR_H_
