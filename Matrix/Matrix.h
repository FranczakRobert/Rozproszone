//
// Created by Robert Franczak on 13/03/2024.
//

#ifndef ZADANIE_MATRIX_H
#define ZADANIE_MATRIX_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


#define ROW 0
#define COL 1

class Matrix {
private:
    int matrixSize[2];
    int** matrix;
    void setMatrixSize(int* tab);
public:
    Matrix();
    Matrix(int** matrix, int row, int col);
    int** createMatrix(std::string content, int* tab);
    int* getSize();
    int** getMatrix();
};


#endif //ZADANIE_MATRIX_H
