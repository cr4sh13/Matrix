//
// Created by salvatore on 12/08/18.
//

#ifndef MATRIXLAB_MATRIXFACTORY_H
#define MATRIXLAB_MATRIXFACTORY_H

#include "Matrix.h"

template <typename T>
class MatrixFactory {

public:

    MatrixFactory() {}

    virtual ~MatrixFactory() {}

    Matrix<T> *choiceMatrixType(int x, int y) {
        Matrix<T> *mtx;
        mtx = createMatrix(x, y);
        return mtx;
    }

    virtual Matrix<T> *createMatrix(int x, int y)  = 0;

};


#endif //MATRIXLAB_MATRIXFACTORY_H
