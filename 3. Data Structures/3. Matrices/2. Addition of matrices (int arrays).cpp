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

void addMatrices(int matrix1[rows][columns], int matrix2[rows][columns], int result[rows][columns]){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main(){
    int matrixA[rows][columns] = {{1,2,3},{4,5,6},{7,8,9}};
    int matrixB[rows][columns] = {{1,2,3},{4,5,6},{7,8,9}};
    int matrixC[rows][columns];

    addMatrices(matrixA, matrixB, matrixC);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << matrixC[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}