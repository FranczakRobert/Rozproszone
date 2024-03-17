//
// Created by Robert Franczak on 14/03/2024.
//

#ifndef ZADANIE_MATRIXCONTROLLER_H
#define ZADANIE_MATRIXCONTROLLER_H
#include <iostream>
#include <string>
#include "Matrix.h"

class MatrixController {
public:
    void showMatrix(Matrix matrix, int** matrixA);
    Matrix* multiplyMatrices(Matrix* matrixA, Matrix* matrixB);
    void freeMatrix(int** matrix, int numRows);

};


#endif //ZADANIE_MATRIXCONTROLLER_H
