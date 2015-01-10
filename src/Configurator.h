/**
 * Configurater.h<br>
 * Copyright
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
        * \param configFile コンフィグレーションファイル名（/path/to/file）
         */
        Configurator(std::string configFile);

        //! デストラクタ
        virtual ~Configurator();

        //! コンフィグレーションファイルから設定データを読み込む
         /*!
          *
          */
        void readConfigurationData();
        //!
        /*!
         * \return オブジェクトファイル名
         */
        int getCheckInterval() { return checkInterval_; };
        //!
        /*!
         * \return オブジェクトファイル名
         */
        std::string getBaseURL() { return baseUrl_; };
        //!
        /*!
         * \return オブジェクトファイル名
         */
        std::vector<std::string> getJobs() { return jobs_; };
        //!
        /*!
         * \return オブジェクトファイル名
         */
        std::string getConfigFile() { return configFile_; };

    protected:
        //!
        /*!
         * \param name モジュール名
         */
        void parseData(std::map<std::string, std::string> datas);
        //!
        /*!
         * \param name モジュール名
         */
        void split(const std::string &str, char delimiter, std::string& key, std::string& value);
        //!
        /*!
         * \param name モジュール名
         */
        /*!
         * \return オブジェクトファイル名
         */
        bool isCommentLine(std::string dataString);
        //!
        /*!
         * \param name モジュール名
         */
        void parseIntervalTime(std::map<std::string, std::string> configData);
        //!
        /*!
         * \param name モジュール名
         */
        void parseUrl(std::map<std::string, std::string> configData);

    private:
        //!
        Configurator();
        FileDAO fileDao_; //!<
        std::string configFile_; //!<
        int checkInterval_; //!<
        std::string baseUrl_; //!<
        std::vector<std::string> jobs_; //!<
};

#endif  // CONFIGURATOR_H_
