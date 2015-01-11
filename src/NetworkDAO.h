/**
 * NetworkDAO.h<br>
 * ネットワーククライアントクラス
 *
 * サーバにTCPで接続しデータを取得する<br>
 * IInputterインターフェースを実現する
 *
 * Copyright Yoshihiro Furukawa
 *
 */

#ifndef NETWORKDAO_H_
#define NETWORKDAO_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include "IInputter.h"

class NetworkDAO : public IInputter {
  public:
    //! コンストラクタ
    NetworkDAO();

    //! コンストラクタ
    /**
     * \param[in] url 接続先サーバのホスト名とポート番号　形式　ホスト名:ポート番号
     */
    NetworkDAO(std::string url);

    //! デストラクタ
    virtual ~NetworkDAO();

    //! サーバとのTCPコネクションを確立する
    /**
     * サーバ名またはIPアドレスで指定されたサーバに対し、指定されたポート番号でコネクションを確立する<br>
     * コネクションの確立に失敗した場合は、例外をスローする
     * \param[in] url 接続先サーバのホスト名とポート番号　形式　ホスト名:ポート番号
     * \exception NetworkException コネクションの確立失敗メッセージ
     */
    virtual void openInputter( std::string url );

    //! サーバとのコネクションを切断する
    virtual void closeInputter();

    //! サーバから取得したデータを1行づつ返す
    /**
     * \return 読み込んだ行
     */
    virtual std::string readData();

    //! 何もしない
    virtual bool isExsist ( std::string name );

    //! サーバへメッセージを送信する
    /**
     * サーバへメッセージを送信する<br>
     * メッセージの送信に失敗した場合は、例外をスローする
     * \param[in] requestMessage 送信文字列
     * \exception NetworkException 文字列の送信失敗メッセージ
     */
    virtual void sendRequest(const std::string& requestMessage);

  protected:
    //! 通信用ソケットを準備する
    void prepareSocket();

    //! 接続先サーバの情報を設定する
    /**
     * \param[in] url 接続先サーバのホスト名とポート番号　形式　ホスト名:ポート番号
     */
    void initializeServerInformation(const std::string& url);

    //! 設定されたURL文字列からホスト名を抜き出す
    /**
     * \param[in] url 接続先サーバのホスト名とポート番号　形式　ホスト名:ポート番号
     * \return ホスト名（IPアドレス）
     */
    std::string substringHostNameFromconfiguredURL(const std::string& url);

    //! 設定されたURL文字列からポート番号を抜き出す
    /**
     * \param[in] url 接続先サーバのホスト名とポート番号　形式　ホスト名:ポート番号
     */
    int substringPortNumberFromConfiguredURL(const std::string& url);

    //! 文字列を分割する
    /**
     * \param[in] url 接続先サーバのホスト名とポート番号　形式　ホスト名:ポート番号
     * \param[in] delimiter 分割文字
     * \param[out] hostName 取り出されたホスト名
     * \param[out] port 取り出されたポート番号
     */
    void split(std::string url, char delimiter, std::string& hostName, std::string& port);

    //! gethostbyname関数が成功したか否か
    /**
     * \param[in] host ホスト情報
     * \return 成功したか否か（true : 成功）
     */
    bool isSuccessGethostbyname(struct hostent* host);

    //! ドット表記のIPアドレスからバイナリデータへの変換が成功したか否か
    /**
     * \return 成功したか否か（true : 成功）
     */
    bool isSuccessIPAddressResolution();

    //! ホスト名のアドレス解決をする
    /**
     * \param[in] url 接続先サーバのホスト名とポート番号　形式　ホスト名:ポート番号
     * \return 解決結果
     */
    struct hostent* resolveIPAddressWithHostName(const std::string& url);

    int socket_; //!< ソケット番号
    struct sockaddr_in server_; //!< サーバ情報
};

#endif  // NETWORKDAO_H_
