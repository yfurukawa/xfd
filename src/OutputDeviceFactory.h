/**
 * OutputDeviceFactory.h<br>
 * Copyright
 *
 */

#ifndef OUTPUTDEVICEFACTORY_H_
#define OUTPUTDEVICEFACTORY_H_

#include <iostream>

class OutputDeviceFactory {
    public:
        //! デストラクタ
        virtual ~OutputDeviceFactory();

        //! シングルトンにするためのインスタンス生成用メソッド
        static OutputDeviceFactory& getInstance();
    private:
        //! コンストラクタ
        OutputDeviceFactory() {}
        OutputDeviceFactory(const OutputDeviceFactory& own) {}
        OutputDeviceFactory& operator=(const OutputDeviceFactory& own){}
};

#endif  // OUTPUTDEVICEFACTORY_H_
