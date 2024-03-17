//
// Created by Robert Franczak on 13/03/2024.
//

#include "Matrix.h"

Matrix::Matrix(int** matrix, int row, int col) {
    this->matrix = matrix;
    this->matrixSize[ROW] =row;
    this->matrixSize[COL] =col;
}

int** Matrix::createMatrix(std::string content, int* tab) {
    setMatrixSize(tab);
    this->matrix = new int*[matrixSize[ROW]];

    for (int i = 0; i < matrixSize[ROW]; ++i) {
        this->matrix[i] = new int[matrixSize[COL]];
    }
    std::istringstream iss(content);

    for (int i = 0; i < matrixSize[ROW]; ++i) {
        for (int j = 0; j < matrixSize[COL]; ++j) {
            iss >> matrix[i][j];
        }
    }
    return matrix;
}

void Matrix::setMatrixSize(int* tab){
    matrixSize[0] = tab[0];
    matrixSize[1] = tab[1];
}

int* Matrix::getSize() {
    return matrixSize;
}

int **Matrix::getMatrix() {
    return matrix;
}

Matrix::Matrix() {

}


