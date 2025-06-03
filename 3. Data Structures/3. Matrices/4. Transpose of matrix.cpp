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
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[rows][columns], int result[columns][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrixA[rows][columns] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int transposedMatrix[columns][rows];

    transposeMatrix(matrixA, transposedMatrix);

    cout << "A : " << endl;
    print(matrixA);

    cout << endl;

    cout << "A^T : " << endl;
    print(transposedMatrix);

    return 0;
}