//
// Created by salvatore on 12/08/18.
//

#ifndef MATRIXLAB_MATRIXTYPE_H
#define MATRIXLAB_MATRIXTYPE_H

#include "Matrix.h"
#include "SquareMatrix.h"
#include "RowMatrix.h"
#include "ColMatrix.h"
#include "RectangleMatrix.h"
#include "MatrixFactory.h"

template<typename T>
class MatrixType : public MatrixFactory<T> {

public:
    Matrix<T> *createMatrix(int x, int y) {
        if (x == y && x > 0)
            return new SquareMatrix<T>(x);
        else if (x == 1 && y > 0)
            return new RowMatrix<T>(1, y);
        else if (x > 0 && y == 1)
            return new ColMatrix<T>(x, 1);
        else if (x > 0 && y > 0 && x != y)
            return new RectangleMatrix<T>(x, y);
        else return 0;
    }

};


#endif //MATRIXLAB_MATRIXTYPE_H
