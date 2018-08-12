#include <iostream>
#include "Matrix.h"
#include "MatrixFactory.h"
#include "MatrixType.h"

using namespace std;

int main() {

    MatrixFactory<int>* mtx1 = new MatrixType<int>();
    Matrix<int>* matrix1 = mtx1->choiceMatrixType(3,3);
    matrix1->insertValues();
    matrix1->typeOfMatrix();
    matrix1->printMatrix();




    return 0;
}