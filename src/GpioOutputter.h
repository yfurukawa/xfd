/**
 * GpioOutputter.h<br>
 * Copyright
 *
 */

#ifndef GPIOOUTPUTTER_H_
#define GPIOOUTPUTTER_H_

#include "IOutputter.h"

class GpioOutputter : public IOutputter {
 public:
  //! コンストラクタ
  GpioOutputter();

  //! デストラクタ
  virtual ~GpioOutputter();

  //! ジョブの結果を出力する
  /**
   * \param outputName 未使用
   * \param contents ジョブの結果（successまたはfail）
   */
  virtual void outputContents( std::string outputName, std::string contents );
 protected:
 private:
};

#endif  // GPIOOUTPUTTER_H_
