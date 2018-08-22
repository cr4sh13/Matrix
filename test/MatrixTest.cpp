#include "gtest/gtest.h"

#include "../MatrixType.h"

TEST(Matrix, testSquare) {
    MatrixFactory<int> *mtp = new MatrixType<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(4, 4);
    ASSERT_EQ(matrix->getType() == "Square matrix", true);
}

TEST(Matrix, testRectangle) {
    MatrixFactory<int> *mtp = new MatrixType<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(2, 4);
    ASSERT_EQ(matrix->getType() == "Rectangle matrix", true);
}

TEST(Matrix, testRow) {
    MatrixFactory<int> *mtp = new MatrixType<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(1, 4);
    ASSERT_EQ(matrix->getType() == "Row matrix", true);
}

TEST(Matrix, testCol) {
    MatrixFactory<int> *mtp = new MatrixType<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(4, 1);
    ASSERT_EQ(matrix->getType() == "Column matrix", true);
}

TEST(MatrixFactory, intCtorTest) {
    MatrixFactory<int> *mtp = new MatrixType<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(5, 5);
    int value = matrix->getValue(5, 5);
    ASSERT_EQ(value == 0, true);
}

TEST(MatrixFactory, doubleCtorTest) {
    MatrixFactory<double> *mtp = new MatrixType<double>();
    Matrix<double> *matrix = mtp->choiceMatrixType(5, 5);
    double value = matrix->getValue(5, 5);
    ASSERT_EQ(value == 0, true);
}

TEST (Matrix, testGetValue) {
    MatrixFactory<int> *mtp = new MatrixType<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(5, 5);
    int value = 1;
    value = matrix->getValue(2, 3);
    ASSERT_EQ(value == 0, true);
}

TEST(Matrix, intTestSetValue) {
    MatrixFactory<int> *mtp = new MatrixType<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(5, 5);
    matrix->setValue(2, 3, 1);
    matrix->setValue(2, 3, 5);
    int value = 0;
    value = matrix->getValue(2, 3);
    ASSERT_EQ(value == 5, true);
}

TEST(Matrix, doubleTestSetValue) {
    MatrixFactory<double> *mtp = new MatrixType<double>();
    Matrix<double> *matrix = mtp->choiceMatrixType(5, 5);
    matrix->setValue(2, 3, 1.00005);
    matrix->setValue(2, 3, 5.0009);
    double value = 0;
    value = matrix->getValue(2, 3);
    ASSERT_EQ(value == 5.0009, true);
}

TEST(Matrix, TestReturnRow) {
    MatrixFactory<int> *mtp = new MatrixType<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(2, 2);
    MatrixFactory<int> *mtp1 = new MatrixType<int>();
    Matrix<int> *matrix1 = mtp->choiceMatrixType(2, 2);
    MatrixFactory<int> *mtp2 = new MatrixType<int>();
    Matrix<int> *matrix2 = mtp->choiceMatrixType(1, 2);
    matrix->setValue(1, 1, 1);
    matrix->setValue(1, 2, 2);
    matrix->setValue(2, 1, 3);
    matrix->setValue(2, 2, 4);
    matrix2->setValue(1, 1, 1);
    matrix2->setValue(1, 2, 2);
    *matrix1 = matrix->rowMatrix(1);
    bool ans = false;
    for (int i = 1; i <= matrix1->getRow(); ++i) {
        for (int j = 1; j <= matrix1->getColumns(); ++j) {
            if (matrix1->getValue(i, j) != matrix2->getValue(i, j)) {
                ans = false;
                ASSERT_EQ(ans, true);
            } else
                ans = true;
        }
    }

    ASSERT_EQ(ans, true);
}

TEST(Matrix, TestReturnCol) {
    MatrixFactory<int> *mtp = new MatrixType<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(2, 2);
    MatrixFactory<int> *mtp1 = new MatrixType<int>();
    Matrix<int> *matrix1 = mtp->choiceMatrixType(2, 2);
    MatrixFactory<int> *mtp2 = new MatrixType<int>();
    Matrix<int> *matrix2 = mtp->choiceMatrixType(2, 1);
    matrix->setValue(1, 1, 1);
    matrix->setValue(1, 2, 2);
    matrix->setValue(2, 1, 3);
    matrix->setValue(2, 2, 4);
    matrix2->setValue(1, 1, 1);
    matrix2->setValue(2, 1, 3);
    *matrix1 = matrix->colMatrix(1);
    bool ans = false;
    for (int i = 1; i <= matrix1->getRow(); ++i) {
        for (int j = 1; j <= matrix1->getColumns(); ++j) {
            if (matrix1->getValue(i, j) != matrix2->getValue(i, j)) {
                ans = false;
                ASSERT_EQ(ans, true);
            } else
                ans = true;
        }
    }

    ASSERT_EQ(ans, true);
}


TEST(Matrix, TestTrasp) {
    MatrixFactory<int> *mtp = new MatrixType<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(2, 2);
    MatrixFactory<int> *mtp1 = new MatrixType<int>();
    Matrix<int> *matrix1 = mtp->choiceMatrixType(2, 2);
    MatrixFactory<int> *mtp2 = new MatrixType<int>();
    Matrix<int> *matrix2 = mtp->choiceMatrixType(2, 2);
    matrix->setValue(1, 1, 1);
    matrix->setValue(1, 2, 2);
    matrix->setValue(2, 1, 3);
    matrix->setValue(2, 2, 4);
    matrix2->setValue(1, 1, 1);
    matrix2->setValue(1, 2, 3);
    matrix2->setValue(2, 1, 2);
    matrix2->setValue(2, 2, 4);
    *matrix1 = matrix->trasp();
    bool ans = false;
    for (int i = 1; i <= matrix1->getRow(); ++i) {
        for (int j = 1; j <= matrix1->getColumns(); ++j) {
            if (matrix1->getValue(i, j) != matrix2->getValue(i, j)) {
                ans = false;
                ASSERT_EQ(ans, true);
            } else
                ans = true;
        }
    }
    ASSERT_EQ(ans, true);
}


TEST(Matrix, TestOperatorMultpl) {
    MatrixFactory<int> *mtp = new MatrixType<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(2, 2);
    MatrixFactory<int> *mtp1 = new MatrixType<int>();
    Matrix<int> *matrix1 = mtp->choiceMatrixType(2, 2);
    MatrixFactory<int> *mtp2 = new MatrixType<int>();
    Matrix<int> *matrix2 = mtp->choiceMatrixType(2, 2);
    MatrixFactory<int> *mtp3 = new MatrixType<int>();
    Matrix<int> *matrix3 = mtp->choiceMatrixType(2, 2);
    matrix->setValue(1, 1, 1);
    matrix->setValue(1, 2, 2);
    matrix->setValue(2, 1, 3);
    matrix->setValue(2, 2, 4);
    matrix2->setValue(1, 1, 7);
    matrix2->setValue(1, 2, 10);
    matrix2->setValue(2, 1, 15);
    matrix2->setValue(2, 2, 22);
    matrix3->setValue(1, 1, 1);
    matrix3->setValue(1, 2, 2);
    matrix3->setValue(2, 1, 3);
    matrix3->setValue(2, 2, 4);
    *matrix1 = (*matrix) * (*matrix3);
    bool ans = false;
    for (int i = 1; i <= matrix1->getRow(); ++i) {
        for (int j = 1; j <= matrix1->getColumns(); ++j) {
            if (matrix1->getValue(i, j) != matrix2->getValue(i, j)) {
                ans = false;
                ASSERT_EQ(ans, true);
            } else
                ans = true;
        }
    }
    ASSERT_EQ(ans, true);
}

TEST(Matrix, TestOperatorMultplAdd) {
    MatrixFactory<int> *mtp = new MatrixType<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(2, 2);
    MatrixFactory<int> *mtp1 = new MatrixType<int>();
    Matrix<int> *matrix1 = mtp->choiceMatrixType(2, 2);
    MatrixFactory<int> *mtp2 = new MatrixType<int>();
    Matrix<int> *matrix2 = mtp->choiceMatrixType(2, 2);
    MatrixFactory<int> *mtp3 = new MatrixType<int>();
    Matrix<int> *matrix3 = mtp->choiceMatrixType(2, 2);
    matrix->setValue(1, 1, 1);
    matrix->setValue(1, 2, 2);
    matrix->setValue(2, 1, 3);
    matrix->setValue(2, 2, 4);
    matrix2->setValue(1, 1, 2);
    matrix2->setValue(1, 2, 4);
    matrix2->setValue(2, 1, 6);
    matrix2->setValue(2, 2, 8);
    matrix3->setValue(1, 1, 1);
    matrix3->setValue(1, 2, 2);
    matrix3->setValue(2, 1, 3);
    matrix3->setValue(2, 2, 4);
    *matrix1 = (*matrix) + (*matrix3);
    bool ans = false;
    for (int i = 1; i <= matrix1->getRow(); ++i) {
        for (int j = 1; j <= matrix1->getColumns(); ++j) {
            if (matrix1->getValue(i, j) != matrix2->getValue(i, j)) {
                ans = false;
                ASSERT_EQ(ans, true);
            } else
                ans = true;
        }
    }
    ASSERT_EQ(ans, true);
}