//
// Created by salvatore on 12/08/18.
//

#ifndef MATRIXLAB_MATRIXTYPE_H
#define MATRIXLAB_MATRIXTYPE_H

#include "Matrix.h"
#include "MatrixFactory.h"

template<typename T>
class MatrixType : public MatrixFactory<T> {

public:
    Matrix<T> *createMatrix(int x, int y) throw(std::out_of_range) {
        Matrix<T>* matrix;
        if (x == y && x > 1) {
            matrix = new Matrix<T>(x, y);
            matrix->setType("Square matrix");
        } else if (x == 1 && y > 0) {
            matrix = new Matrix<T>(1, y);
            matrix->setType("Row matrix");
        } else if (x > 0 && y == 1) {
            matrix = new Matrix<T>(x, 1);
            matrix->setType("Column matrix");
        }else if (x > 1 && y > 1 && x != y) {
            matrix = new Matrix<T>(x, y);
            matrix->setType("Rectangle matrix");
        }else {
            throw std::out_of_range("Rows and columns must be positive.");
        }

        return matrix;
    }

};


#endif //MATRIXLAB_MATRIXTYPE_H
