//
// Created by Robert Franczak on 14/03/2024.
//

#include "MatrixController.h"

void MatrixController::showMatrix(Matrix matrix, int **matrixA) {
    for (int i = 0; i < matrix.getSize()[0]; ++i) {
        for (int j = 0; j <  matrix.getSize()[1]; ++j) {
            std::cout << matrixA[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix* MatrixController::multiplyMatrices(Matrix* matrixA, Matrix* matrixB) {
    if (matrixA->getSize()[COL] !=matrixB->getSize()[ROW]) {
        std::cerr << "Nie można pomnożyć macierzy - niezgodne rozmiary." << std::endl;
        return nullptr;
    }

    int **result = new int* [matrixA->getSize()[ROW]];
    int numRowsC = matrixA->getSize()[ROW];
    int numColsC = matrixB->getSize()[COL];

    for (int i = 0; i < matrixA->getSize()[ROW]; ++i) {
        result[i] = new int[matrixB->getSize()[COL]];
        for (int j = 0; j < matrixB->getSize()[COL]; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < matrixA->getSize()[COL]; ++k) {
                result[i][j] += matrixA->getMatrix()[i][k] * matrixB->getMatrix()[k][j];
            }
        }
    }
    return new Matrix(result,numRowsC,numColsC);

}

void MatrixController::freeMatrix(int** matrix, int numRows) {
    for (int i = 0; i < numRows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
