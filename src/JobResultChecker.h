/**
 * JobResultChecker.h<br>
 * Jenkinsのジョブの結果を確認する
 *
 * JenkinsのWebAPIを通じ最新結果を取得し成功したか否かをチェックする
 * Copyright
 *
 */

#ifndef JOBRESULTCHECKER_H_
#define JOBRESULTCHECKER_H_

#include <string>
#include "JsonParser.h"

class NetworkDAO;

class JobResultChecker {
public:
    //! コンストラクタ
    /**
     * \param[in] jobName Jenkinsに登録されてい監視対象にするジョブ名
     * \param[in] url 接続先サーバのホスト名とポート番号　形式　ホスト名:ポート番号
     * \param[in] networkDao ネットワークにアクセスするためのデータアクセスオブジェクト
     */
    explicit JobResultChecker(const std::string jobName, const std::string& url, NetworkDAO* networkDao);

    //! デストラクタ
    virtual ~JobResultChecker();

    //! 監視対象のジョブ名を返す
    /**
     * \return 監視対象ジョブ名
     */
    std::string getJobName();

    //! 結果を確認する
    /**
     * 結果確認時に問題が発生した場合には例外をスローする
     * \return ジョブの結果（true : 成功）
     * \exception NetworkException 通信の問題内容
     */
    bool checkResult();

protected:

    //! JenkinsのWebAPIに接続し、結果を取得する
    /**
     * GETメッセージの送信に失敗した場合に例外をスローする
     * \exception NetworkException 通信の問題内容
     */
    void sendRequestMessageToJenkins();

    //! Jenkinsから取得した結果を確認する
    /**
     * \return 判定結果（true : 成功）
     */
    bool judgeJenkinsJobResult();

    //! Jenkinsから取得したデータが、JSON文字列かどうか判定する
    /**
     * \param[in] readData Jenkinsから取得した文字列
     * \return 判定結果（true : JSON文字列）
     */
    bool isJsonString(std::string readData);

    const std::string jobName_; //!< 監視対象ジョブ名
    NetworkDAO* networkDao_; //!< ネットワークアクセスオブジェクト
    JsonParser parser; //!< JSON文字列のパーサオブジェクト
    std::string url_;  //!< 接続先サーバのホスト名とポート番号　形式　ホスト名:ポート番号

private:
    //! コンストラクタ
    JobResultChecker();
};

#endif  // JOBRESULTCHECKER_H_
