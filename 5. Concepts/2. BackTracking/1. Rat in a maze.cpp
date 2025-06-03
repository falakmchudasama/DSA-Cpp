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

// Rat in a maze 

bool isSafe(const vector<vector<int>>& inputMatrix, int x, int y, int n){
    if((x >= n || y >= n) || inputMatrix[x][y] == 0){
        return false;
    }
    return true;
}

bool ratInMaze(const vector<vector<int>>& inputMatrix, int x, int y, int n, vector<vector<int>>& outputMatrix){
    if(x == n-1 && y == n-1){
        outputMatrix[x][y] = 1;
        return true;
    }
    if(isSafe(inputMatrix, x, y, n)){
        outputMatrix[x][y] = 1;
        if(ratInMaze(inputMatrix, x, y+1, n, outputMatrix)){
            return true;
        }
        if(ratInMaze(inputMatrix, x+1, y, n, outputMatrix)){
            return true;
        }
        outputMatrix[x][y] = 0;
        return false;
    }
    return false;
}

int main(){
    int n = 3;
    vector<vector<int>> outputM = {
        {0,0,0},
        {0,0,0},
        {0,0,0},
    };
    vector<vector<int>> inputM= {
        {1,1,1,},
        {1,0,1,},
        {1,1,1,},
    };

    ratInMaze(inputM, 0, 0, n, outputM);

    int row = n;
    int col = n;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < n; j++){
            cout << outputM[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}