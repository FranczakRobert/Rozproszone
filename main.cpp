#include "File/FileController.h"
#include "Matrix/Matrix.h"
#include "Matrix/MatrixController.h"

int main() {
    Matrix matrixA;
    Matrix matrixB;
    MatrixController matrixController;

    FileController fileController("/Users/robertfranczak/Documents/ZUT/ZUT MATERIAŁY/Rok 3/Semestr II/Przetwarzanie Rozproszone/macierze/matrixA.txt");
    fileController.readFromFile();

    int** a = matrixA.createMatrix(fileController.getContentString(), fileController.getMatrixSizeArray());
    matrixController.showMatrix(matrixA,a);

    std::cout << std::endl;

    fileController.setPath("/Users/robertfranczak/Documents/ZUT/ZUT MATERIAŁY/Rok 3/Semestr II/Przetwarzanie Rozproszone/macierze/matrixB.txt");
    fileController.readFromFile();

    int** b = matrixB.createMatrix(fileController.getContentString(), fileController.getMatrixSizeArray());
    matrixController.showMatrix(matrixB,b);

    Matrix* c = matrixController.multiplyMatrices(&matrixA,&matrixB);

    fileController.writeMatrixToFile("matrixC.txt",c,c->getSize()[ROW],c->getSize()[COL]);

    matrixController.freeMatrix(a,matrixA.getSize()[ROW]);
    matrixController.freeMatrix(b,matrixB.getSize()[ROW]);
    matrixController.freeMatrix(c->getMatrix(),c->getSize()[ROW]);

    delete c;

    return 0;
}

