//
// Created by Robert Franczak on 13/03/2024.
//
#include <iostream>
#include <fstream>
#include <string>
#include "../Matrix/Matrix.h"

#ifndef ZADANIE_FILEREADER_H
#define ZADANIE_FILEREADER_H

struct Flags{
    bool sizeFlag = 0;
};

class FileController {
private:
    std::ifstream matrixFile;
    struct Flags flags;
    int matrixSize[2];
    std::string content;
    std::string path;

    void setSize(std::string line);
    void setFileContent( std::string line);

public:
    FileController(std::string path);

    void readFromFile();
    void setPath(std::string path);
    int* getMatrixSizeArray();
    std::string getContentString();
    void writeMatrixToFile(const char* filename,  Matrix* matrix, int numRows, int numCols);

};

#endif //ZADANIE_FILEREADER_H
