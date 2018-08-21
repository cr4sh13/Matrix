#include <iostream>
#include "Matrix.h"
#include "MatrixFactory.h"
#include "MatrixType.h"
#include <stdexcept>


int main() {

    try {

        std::string anwser;
        int value, row, column;

        MatrixFactory<int> *intFactory = new MatrixType<int>();
        Matrix<int> *imatrix = intFactory->choiceMatrixType(2, 2);
        std::cout << "MATRIX OF INTEGERS";
        imatrix->insertRandomValues();
        imatrix->printMatrix();
        std::cout << std::endl;

        MatrixFactory<float> *floatFactory = new MatrixType<float>;
        std::cout << "FIRST MATRIX OF FLOATS";
        Matrix<float> *fmatrix = floatFactory->choiceMatrixType(2, 2);
        fmatrix->insertRandomValues();
        fmatrix->printMatrix();
        std::cout << std::endl;


        std::cout << "SECOND MATRIX OF FLOATS";
        Matrix<float> *fsmatrix = floatFactory->choiceMatrixType(2, 2);
        fsmatrix->insertRandomValues();
        fsmatrix->printMatrix();
        std::cout << std::endl;

        std::cout << "MOLTIPLICATION OF FLOAT MATRIX";
        Matrix<float> *rs = floatFactory->choiceMatrixType(2, 2);
        (*rs) = (*fmatrix) * (*fsmatrix);
        rs->printMatrix();


        std::cout << "TRANSPOSE OF INT MATRIX";
        imatrix->trasp();
        imatrix->printMatrix();


        Matrix<int> *firstMatrix = intFactory->choiceMatrixType(2, 2);
        std::cout << "copying int matrix to first matrix..." << std::endl;
        firstMatrix = imatrix;
        std::cout << "\nFIRST MATRIX";
        firstMatrix->printMatrix();

        Matrix<int> *secondMatrix = intFactory->choiceMatrixType(2, 3);
        secondMatrix->insertRandomValues();

        Matrix<int> *resultMatrix = intFactory->choiceMatrixType(2, 3);

        std::cout << "MOLTIPLICATION OF TWO MATRIX";
        *resultMatrix = (*firstMatrix) * (*secondMatrix);
        resultMatrix->printMatrix();


        std::cout << "\nMODIFYING MATRIX ELEMENT" << std::endl;

        std::cout << "Insert new value: ";
        std::cin >> value;
        std::cout << "Insert target's row: ";
        std::cin >> row;
        std::cout << "Insert target's columns: ";
        std::cin >> column;
        resultMatrix->setValue(row, column, value);

        std::cout << "NEW MODIFIED MATRIX";
        resultMatrix->printMatrix();
    }
    catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
        return 36;
    }

    return 0;
}