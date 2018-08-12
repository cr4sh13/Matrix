//
// Created by salvatore on 11/08/18.
//

#ifndef MATRIXLAB_SQUAREMATRIX_H
#define MATRIXLAB_SQUAREMATRIX_H

#include "Matrix.h"

template <typename T>
class SquareMatrix : public Matrix<T>{

public:
    SquareMatrix() {}

    SquareMatrix(int x) : Matrix<T>(x, x) {
        this->setType("Square Matrix");
    }

    virtual ~SquareMatrix() {}

    virtual void typeOfMatrix() const override {
        Matrix<T>::typeOfMatrix();
        std::cout << this->getType() << std::endl << std::endl;
    }

};


#endif //MATRIXLAB_SQUAREMATRIX_H
