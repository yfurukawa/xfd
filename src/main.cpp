/*
 * make.cpp
 *
 *  Created on: 2015/01/08
 *      Author: yoshi
 */
#include "Conductor.h"

int main(int argc, char* argv[]) {
    Conductor* conductor_;
    if(argc == 2){
        conductor_ = new Conductor(argv[1]);
    }
    else {
        conductor_ = new Conductor();
    }
    conductor_->execute(&argc, &argv);

    delete conductor_;
    return 0;
}

