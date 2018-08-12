//
// Created by salvatore on 11/08/18.
//

#ifndef MATRIXLAB_ROWMATRIX_H
#define MATRIXLAB_ROWMATRIX_H

#include "Matrix.h"


template<typename T>
class RowMatrix : public Matrix<T> {

public:
    RowMatrix() {}

    RowMatrix(int x, int y) : Matrix<T>(1, y) {
        this->setType("Row Matrix");
    }

    virtual ~RowMatrix() {}

    virtual void typeOfMatrix() const override {
        Matrix<T>::typeOfMatrix();
        std::cout << this->getType() << std::endl << std::endl;
    }

};


#endif //MATRIXLAB_ROWMATRIX_H
