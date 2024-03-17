//
// Created by Robert Franczak on 13/03/2024.
//
#include "../Matrix/Matrix.h"
#include "FileController.h"

FileController::FileController(std::string path) {
    this->path = path;
}

void FileController::readFromFile() {
    matrixFile.open(this->path);
    std::cout << this->path << std::endl;
    std::string line;

    if(matrixFile) {
        while (std::getline(matrixFile, line)) {
            if(!flags.sizeFlag) {
                setSize(line);
                flags.sizeFlag = 1;
            } else {
                setFileContent(line);
            }
        }
    }
    matrixFile.close();
}

void FileController::writeMatrixToFile(const char* filename, Matrix* matrix, int numRows, int numCols) {
    std::string filePath = "../" + std::string(filename);
    std::ofstream file(filePath);

    if (file.is_open()) {
        file << matrix->getSize()[0];
        file << 'x';
        file << matrix->getSize()[1];
        file << std::endl;

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                file << matrix->getMatrix()[i][j] << " ";
            }
            file << std::endl;
        }

        std::cout << "Plik " << filename << " został pomyślnie zapisany." << std::endl;
        file.close();
    } else {
        std::cerr << "Błąd podczas otwierania pliku." << std::endl;
    }
}

void FileController::setSize(std::string line) {
    int pos = line.find('x');
    if (pos != std::string::npos) {
        std::string row = line.substr(0, pos);
        std::string col = line.substr(pos + 1);
        matrixSize[0] = std::stoi(row);
        matrixSize[1] = std::stoi(col);
    }
}

void FileController::setFileContent(std::string line) {
    content += line + "\n";
}

int* FileController::getMatrixSizeArray() {
    return matrixSize;
}

std::string FileController::getContentString() {
    return content;
}

void FileController::setPath(std::string path) {
    this->path = path;
    flags.sizeFlag = 0;
    content = "";
}
