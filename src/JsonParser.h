/**
 * jsonParser.h<br>
 * JSON文字列をパースする
 *
 * Jenkinsから取得したJSON文字列をパースする。<br>
 * 実際にパースするのは、json-cライブラリ。<br>
 * https://github.com/json-c/json-c
 *
 * Copyright Yoshihiro Furukawa
 *
 */

#ifndef JSONPARSER_H_
#define JSONPARSER_H_

#include <string>
#include <map>
#include <json-c/json.h>

class JsonParser {
public:
    //! コンストラクタ
    JsonParser();

    //! デストラクタ
    virtual ~JsonParser();

    //! JSON文字列をパースする
    /**
     * \param[in] jsonString パースしたいJSON文字列
     * \return パースしたキーと値のペア
     */
    std::map<std::string, std::string> parse(const std::string jsonString);
};

#endif  // JSONPARSER_H_
