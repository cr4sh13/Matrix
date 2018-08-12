//
// Created by salvatore on 11/08/18.
//

#ifndef MATRIXLAB_COLMATRIX_H
#define MATRIXLAB_COLMATRIX_H

#include "Matrix.h"

template <typename T>
class ColMatrix : public Matrix<T>{

public:

    ColMatrix() {}

    ColMatrix(int x, int y) : Matrix<T>(x, 1) {
        this->setType("Column Matrix");
    }

    virtual ~ColMatrix() {}

    virtual void typeOfMatrix() const override {
        Matrix<T>::typeOfMatrix();
        std::cout << this->getType() << std::endl << std::endl;
    }



};


#endif //MATRIXLAB_COLMATRIX_H
