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

int main(){
    const int rows = 3;
    const int columns = 2;

    int matrix[rows][columns] = {{1,2},{3,4},{5,6}};

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int A32 = matrix[2][1];

    cout << "The element is '" << A32 << "' at A32 position" << endl;

    return 0;
}