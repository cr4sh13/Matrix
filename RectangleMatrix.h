//
// Created by salvatore on 11/08/18.
//

#ifndef MATRIXLAB_RECTANGLEMATRIX_H
#define MATRIXLAB_RECTANGLEMATRIX_H

#include "Matrix.h"

template <typename T>
class RectangleMatrix : public Matrix<T> {

public:
    RectangleMatrix() {}

    RectangleMatrix(int x, int y) : Matrix<T>(x, y) {
        this->setType("Rectangle Matrix");
    }

    virtual ~RectangleMatrix() {}

    virtual void typeOfMatrix() const override {
        Matrix<T>::typeOfMatrix();
        std::cout << this->getType() << std::endl << std::endl;
    }
};


#endif //MATRIXLAB_RECTANGLEMATRIX_H
