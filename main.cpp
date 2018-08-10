#include <iostream>
#include "Matrix.h"

int main() {



    /// Creo matrice con costruttore di deafult
    Matrix<int> newMatrix;
    newMatrix.printMatrix();


    /// Creo matrice 5x5
    Matrix<int> matrix(5, 5);
    matrix.printMatrix();


    return 0;
}