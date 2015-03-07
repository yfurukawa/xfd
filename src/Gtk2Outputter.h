/**
 * Gtk2Outputter.h<br>
 * Copyright
 *
 */

#ifndef GTK2OUTPUTTER_H_
#define GTK2OUTPUTTER_H_

#include <gtk/gtk.h>
#include <string>
#include "IOutputter.h"


class Gtk2Outputter : public IOutputter{
public:
    //! コンストラクタ
    /**
     * \param[in] argc コマンドライン引数
     * \param[in] argv コマンドライン引数
     */
    Gtk2Outputter(int* argc, char*** argv);

    //! デストラクタ
    virtual ~Gtk2Outputter();

    //! ジョブの結果を出力する
    /**
     * \param[in] outputName 未使用
     * \param[in] contents ジョブの結果（successまたはfail）
     */
    virtual void outputContents( std::string outputName, std::string contents );

    //! 出力デバイス名を返す
    /*!
     * \return 出力デバイス名
     */
    virtual std::string getDeviceName() { return "gtk"; };

    //! Windowを初期化する
    /**
     * Windowを初期化する。デバイスの初期化に失敗した場合は例外をスローする。
     * \param[in] argc コマンドライン引数
     * \param[in] argv コマンドライン引数
     * \exception 初期化に失敗したデバイス
     */
    virtual void initializeDevice();

protected:
    //! gtkの親ウィンドウを生成する
    /**
     * \param[out] window 生成されたウィンドウ
     */
    void createWindow();

    //! マルチスレッド用呼出メソッド
    static void* run(void* pParameter);
private:
    //! コンストラクタ
    Gtk2Outputter() : argc_(NULL), argv_(NULL) {
    };


    static GtkWidget* window_; //!< gtkのウィンドウ
    static int width_; //!< キャンバスの横幅[pixel]
    static int hight_; //!< キャンバスの縦幅[pixel]
    static GdkColor bgColor_; //! <
    int* argc_;
    char*** argv_;

};

#endif  // GTK2OUTPUTTER_H_
