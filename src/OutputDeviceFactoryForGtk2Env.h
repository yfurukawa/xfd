/**
 * OutputDeviceFactoryForGtk2Env.h<br>
 * Copyright
 *
 */

#ifndef OUTPUTDEVICEFACTORYFORGTK2ENV_H_
#define OUTPUTDEVICEFACTORYFORGTK2ENV_H_

#include <new>
#include "OutputDeviceFactory.h"
#include "GpioOutputter.h"
#include "Gtk2Outputter.h"

class OutputDeviceFactoryForGtk2Env : public OutputDeviceFactory {
 public:
  //! Constractor
  OutputDeviceFactoryForGtk2Env();
  //! Destructor
  virtual ~OutputDeviceFactoryForGtk2Env();
  virtual std::vector<IOutputter*> getOutputterList(std::vector<std::string> deviceType) const;

  static bool isDestroyed();

 protected:
 private:
  static bool destroyed_;

};

#endif  // OUTPUTDEVICEFACTORYFORGTK2ENV_H_
