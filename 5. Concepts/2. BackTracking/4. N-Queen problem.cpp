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

// N-Queen 
bool isSafe(vector<vector<int>>& Matrix, int x, int y, int n) {
    for (int row = 0; row < x; ++row) {
        if (Matrix[row][y] == 1) {
            return false;
        }
    }

    for (int col = 0; col < y; ++col) {
        if (Matrix[x][col] == 1) {
            return false;
        }
    }

    int rows = x;
    int cols = y;
    while (rows >= 0 && cols >= 0) {
        if (Matrix[rows][cols] == 1) {
            return false;
        }
        --rows;
        --cols;
    }

    rows = x;
    cols = y;
    while (rows >= 0 && cols < n) {
        if (Matrix[rows][cols] == 1) {
            return false;
        }
        --rows;
        ++cols;
    }

    return true;
}

bool nQueen(vector<vector<int>>& Matrix, int x, int n) {
    if (x >= n) {
        return true;
    }
    for (int col = 0; col < n; ++col) {
        if (isSafe(Matrix, x, col, n)) {
            Matrix[x][col] = 1;
            if (nQueen(Matrix, x + 1, n)) {
                return true;
            }
            Matrix[x][col] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> chessBoard(n, vector<int>(n, 0));
    if (nQueen(chessBoard, 0, n)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << chessBoard[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Solution does not exist." << endl;
    }
    return 0;
}
