#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

const int rows = 3;
const int columns = 3;

void print(int matrix[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void transposeMatrix(int matrix[rows][columns], int result[columns][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void modMatrix(int matrix[rows][columns], int modulus) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] %= modulus;
        }
    }
}

int main() {
    int matrixA[rows][columns] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int transposedMatrix[columns][rows];

    std::cout << "Original Matrix:\n";
    print(matrixA);

    transposeMatrix(matrixA, transposedMatrix);

    std::cout << "\nTransposed Matrix:\n";
    print(transposedMatrix);

    int modulus = 3;
    modMatrix(matrixA, modulus);

    cout << "\nModified Matrix (Modulus " << modulus << "):\n";
    print(matrixA);

    return 0;
}