/**
 * GtkOutputter.h<br>
 * Copyright
 *
 */

#ifndef GTKOUTPUTTER_H_
#define GTKOUTPUTTER_H_

#include "IOutputter.h"

class GtkOutputter : public IOutputter{
 public:
  //! コンストラクタ
  GtkOutputter();

  //! デストラクタ
  virtual ~GtkOutputter();

  //! ジョブの結果を出力する
  /**
   * \param outputName 未使用
   * \param contents ジョブの結果（successまたはfail）
   */
  virtual void outputContents( std::string outputName, std::string contents );

 protected:
 private:
};

#endif  // GTKOUTPUTTER_H_
