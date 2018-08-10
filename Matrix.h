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
        this->width = 1;
        this->height = 1;
        value = new T[width * height];
        value[width + (height * width)] = 0;
    }


    Matrix(int x, int y) {
        this->width = x;
        this->height = y;
        value = new T[width * height];
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                value[i + (j * width)] = 0;
            }
        }
    }


    virtual void printMatrix() {
        for (int i = 1; i <= width; i++) {
            for (int j = 1; j <= height; j++) {
                std::cout << this->getValue(i, j) << "\t";

            }
            std::cout << std::endl << std::endl;
        }
    }


    virtual T getValue(int x, int y) {
        if (((x > 0) && (x <= width)) && ((y > 0) && (y <= height)))
            return value[(x - 1) + (y - 1) * width];
    }

private:

    int width, height;
    T *value;
    std::string type;

};


#endif //MATRIXLAB_MATRIX_H
