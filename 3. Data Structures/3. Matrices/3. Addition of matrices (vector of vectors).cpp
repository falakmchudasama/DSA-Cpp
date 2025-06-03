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

void print(vector<vector <int>> matrix){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector <int>> addMatrices(vector<vector <int>> matrix1, vector<vector <int>> matrix2){
    vector<vector <int>> result(rows, vector<int>(columns, 0));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

int main(){
    vector<vector<int>> matrixA = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> matrixB = {{1,2,3},{4,5,6},{7,8,9}};

    vector<vector<int>> matrixC = addMatrices(matrixA,matrixB);
    print(matrixC);

    return 0;
}