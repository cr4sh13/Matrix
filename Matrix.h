//
// Created by salvatore on 28/07/18.
//

#ifndef MATRIXLAB_MATRIX_H
#define MATRIXLAB_MATRIX_H


#include <iostream>

template<typename T>
class Matrix {

public:

    Matrix() {
        this->row = 1;
        this->columns = 1;
        value = new T[row * columns];
        value[row + (columns * row)] = 0;
    }


    Matrix(int x, int y) {
        this->row = x;
        this->columns = y;
        value = new T[row * columns];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < columns; j++) {
                value[i + (j * row)] = 0;
            }
        }
    }


    virtual void printMatrix() {
        std::cout << "\n";
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= columns; j++) {
                std::cout << this->getValue(i, j) << "\t";

            }
            std::cout << std::endl << std::endl;
        }

        std::cout << "\n\n";
    }


    void insertValues() {
        std::cout << std::endl;
        T newValue;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < columns; j++) {
                std::cout << "Insert element at position [" << i + 1 << "][" << j + 1 << "]:";
                std::cin >> newValue;
                value[j + i * columns] = newValue;
            }
        }

    }

    virtual T getValue(int x, int y) const {
        if (((x > 0) && (x <= row)) && ((y > 0) && (y <= columns)))
            return value[(x - 1) + (y - 1) * row];
    }

    virtual void setValue(const int x, const int y, const T val) {
        if ((x > 0) && (y > 0) && (x <= row) && (y <= columns))
            value[(x - 1) + (y - 1) * row] = val;
    }

    virtual ~Matrix() {
        if (value)
            delete[] value;
    }

    virtual Matrix rowMatrix(const int x) {
        Matrix tmp(1, this->row);
        if (x > 0 && x <= this->row) {
            for (int i = 1; i <= this->row; i++)
                tmp.setValue(1, i, this->getValue(x, i));
        }

        return tmp;
    }

    virtual Matrix colMatrix(const int y) {
        Matrix tmp(this->columns, 1);
        if (y > 0 && y <= this->columns) {
            for (int i = 1; i <= this->columns; i++)
                tmp.setValue(i, 1, this->getValue(i, y));
        }

        return tmp;
    }

    virtual Matrix &trasp() {
        if (this->value) {
            Matrix tmp(this->columns, this->row);
            T tempor;
            for (int i = 1; i <= this->row; i++)
                for (int j = i; j <= this->columns; j++) {
                    tempor = this->getValue(i, j);
                    tmp.setValue(i, j, this->getValue(j, i));
                    tmp.setValue(j, i, tempor);
                }
            *this = tmp;
            return *this;
        }
    }


    virtual Matrix operator*(const Matrix &rh) const {
        Matrix<T> tmpMatrix(this->row, rh.columns);
        if (this->columns == rh.row) {
            for (int i = 1; i <= this->row; i++) {
                for (int j = 1; j <= rh.columns; j++) {
                    T tmpValue = 0;
                    for (int k = 1; k <= this->columns; k++) {
                        tmpValue += (this->getValue(i, k) * rh.getValue(k, j));
                        tmpMatrix.setValue(i, j, tmpValue);
                    }
                }
            }
            return tmpMatrix;
        }
    }


    virtual Matrix operator+(const Matrix &rh) const {
        Matrix tmp(rh.row, rh.columns);
        if ((this->row == rh.row) && (this->columns == rh.columns)) {
            for (int i = 1; i <= this->row; i++)
                for (int j = 1; j <= this->columns; j++) {
                    tmp.setValue(i, j, (this->getValue(i, j) + rh.getValue(i, j)));
                }
            return tmp;
        }
    }

    virtual Matrix &operator=(const Matrix &rh) {
        if (this != &rh) {
            this->row = rh.row;
            this->columns = rh.columns;
            for (int i = 1; i <= this->row; i++)
                for (int j = 1; j <= this->columns; j++)
                    this->setValue(i, j, rh.getValue(i, j));
        }
        return *this;
    }

    virtual void typeOfMatrix() const {
        std::cout << "\nI'm a " << row << " x " << columns << " : ";
    }

    virtual int getRow() const {
        return row;
    }

    virtual int getColumns() const {
        return columns;
    }

    virtual const std::string &getType() const {
        return type;
    }

    virtual void setRow(int r) {
        this->row = r;
    }

    virtual void setColumns(int c) {
        this->columns = c;
    }

    virtual void setType(const std::string &t) {
        this->type = t;
    }

private:

    int row, columns;
    T *value;
    std::string type;

};


#endif //MATRIXLAB_MATRIX_H
