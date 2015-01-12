/**
 * GtkOutputter.h<br>
 * Copyright
 *
 */

#ifndef GTKOUTPUTTER_H_
#define GTKOUTPUTTER_H_

#include <gtk/gtk.h>
#include <string>
#include "IOutputter.h"

class GtkOutputter : public IOutputter{
    public:
        //! コンストラクタ
        /**
         * \param[in] argc コマンドライン引数
         * \param[in] argv コマンドライン引数
         */
        GtkOutputter(int* argc, char*** argv);

        //! デストラクタ
        virtual ~GtkOutputter();

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

        //! gtkの表示キャンバスを準備する
        /**
         * ウィンドウ内にジョブの結果を表示するキャンバスを準備する
         */
        void createCanvas();

        //! 表示画面を描画する
        /**
         * jenkinsジョブの結果に対応した表示画面を描画する
         */
        static gboolean draw_canvas(GtkWidget* widget, cairo_t* cr, gpointer data);
    private:
        //! コンストラクタ
        GtkOutputter() : window_(NULL), canvas_(NULL), argc_(NULL), argv_(NULL) {};

        GtkWidget* window_; //!< gtkのウィンドウ
        GtkWidget* canvas_; //!< 表示キャンバス
        static int width_; //!< キャンバスの横幅[pixcel]
        static int hight_; //!< キャンバスの縦幅[pixcel]
        int* argc_;
        char*** argv_;

};

#endif  // GTKOUTPUTTER_H_
