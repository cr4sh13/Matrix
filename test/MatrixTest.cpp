#include "gtest/gtest.h"

#include "../MatrixType.h"


TEST(MatrixFactory, intCtorTest) {
    MatrixFactory<int> *mtp = new MatrixType<int>;
    Matrix<int> *matrix = mtp->choiceMatrixType(3, 3);
    int value = matrix->getValue(3, 3);
    ASSERT_EQ(value == 0, true);
    ASSERT_THROW(Matrix<int>* matrix1 = mtp->choiceMatrixType(0,0), std::out_of_range);
    ASSERT_THROW(Matrix<int>* matrix1 = mtp->choiceMatrixType(-2,-3), std::out_of_range);
}

TEST(MatrixFactory, doubleCtorTest) {
    MatrixFactory<double> *mtp = new MatrixType<double>;
    Matrix<double> *matrix = mtp->choiceMatrixType(3, 3);
    double value = matrix->getValue(3, 3);
    ASSERT_EQ(value == 0, true);
    ASSERT_THROW(Matrix<double >* matrix1 = mtp->choiceMatrixType(0,0), std::out_of_range);
    ASSERT_THROW(Matrix<double >* matrix1 = mtp->choiceMatrixType(-2,-3), std::out_of_range);
}

TEST(MatrixFactory, floatCtorTest) {
    MatrixFactory<float> *mtp = new MatrixType<float>;
    Matrix<float> *matrix = mtp->choiceMatrixType(3, 3);
    float value = matrix->getValue(3, 3);
    ASSERT_EQ(value == 0, true);
    ASSERT_THROW(Matrix<float >* matrix1 = mtp->choiceMatrixType(0,0), std::out_of_range);
    ASSERT_THROW(Matrix<float >* matrix1 = mtp->choiceMatrixType(-2,-3), std::out_of_range);
}

TEST(Matrix, testIntConstructorException){
    ASSERT_THROW(Matrix<int> matrix(0,2), std::out_of_range);
    ASSERT_THROW(Matrix<int> matrix(-1, -3), std::out_of_range);
}


TEST(Matrix, testFloatConstructorException){
    ASSERT_THROW(Matrix<float> matrix(0,2), std::out_of_range);
    ASSERT_THROW(Matrix<float> matrix(-1,-3), std::out_of_range);
}


TEST(Matrix, testRow) {
    MatrixFactory<int> *mtp = new MatrixType<int>;
    Matrix<int> *matrix = mtp->choiceMatrixType(1, 3);
    ASSERT_EQ(matrix->getType() == "Row matrix", true);
    bool flag = false;
    if(matrix->getRow() == 1 && matrix->getColumns() > 0)
        flag = true;
    ASSERT_TRUE(flag);
    ASSERT_THROW(matrix->rowMatrix(2), std::out_of_range);
    ASSERT_THROW(matrix->rowMatrix(-3), std::out_of_range);
}


TEST(Matrix, testCol) {
    MatrixFactory<int> *mtp = new MatrixType<int>;
    Matrix<int> *matrix = mtp->choiceMatrixType(3, 1);
    ASSERT_EQ(matrix->getType() == "Column matrix", true);
    bool flag = false;
    if(matrix->getColumns() == 1 && matrix->getRow() > 0)
        flag = true;
    ASSERT_TRUE(flag);
    ASSERT_THROW(matrix->colMatrix(4), std::out_of_range);
    ASSERT_THROW(matrix->colMatrix(-2), std::out_of_range);
}


TEST (Matrix, testGetValue) {
    MatrixFactory<int> *mtp = new MatrixType<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(5, 5);
    matrix->setValue(2,3,100);
    ASSERT_EQ(matrix->getValue(2,3) == 100, true);
    EXPECT_THROW(matrix->getValue(10,10), std::out_of_range);
    EXPECT_THROW(matrix->getValue(-2,-1), std::out_of_range);
}

TEST(Matrix, intTestSetValue) {
    MatrixFactory<int> *mtp = new MatrixType<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(5, 5);
    matrix->setValue(2, 3, 1);
    ASSERT_EQ(matrix->getValue(2,3) == 1, true);
    EXPECT_THROW(matrix->setValue(10,10,10), std::out_of_range);
    EXPECT_THROW(matrix->setValue(-2,-2,10), std::out_of_range);
}

TEST(Matrix, doubleTestSetValue) {
    MatrixFactory<double> *mtp = new MatrixType<double>();
    Matrix<double> *matrix = mtp->choiceMatrixType(5, 5);
    matrix->setValue(2, 3, 1.00005);
    matrix->setValue(2, 3, 5.0009);
    double value = 0;
    value = matrix->getValue(2, 3);
    ASSERT_EQ(value == 5.0009, true);
    EXPECT_THROW(matrix->setValue(-2,-2,10), std::out_of_range);
    EXPECT_THROW(matrix->setValue(10,10,10), std::out_of_range);
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
    bool flag = false;
    if(matrix1->getRow() == 1 && matrix1->getColumns() >= 1)
        flag = true;
    ASSERT_TRUE(flag);
    EXPECT_THROW(matrix1->rowMatrix(10), std::out_of_range);
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
    bool flag = false;
    if(matrix1->getRow() >=1  && matrix1->getColumns() == 1)
        flag = true;
    ASSERT_TRUE(flag);
    EXPECT_THROW(matrix1->colMatrix(10), std::out_of_range);
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
    Matrix<int> firstMatrix(3,3);
    Matrix<int> secondMatrix(2,2);
    EXPECT_THROW(firstMatrix*secondMatrix, std::out_of_range);
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
    Matrix<int> firstMatrix(3,3);
    Matrix<int> secondMatrix(3,2);
    EXPECT_THROW(firstMatrix+secondMatrix, std::out_of_range);
}
