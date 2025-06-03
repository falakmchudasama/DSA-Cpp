#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int rows = 5;
    int columns = 4;
    int myArray[rows][columns] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}, {17,18,19,20} };

    cout << "{ ";
    for(int i = 0; i < rows; i++){
        cout << "{";
        for(int j = 0; j < columns; j++){
            if (j == columns - 1){
                cout << myArray[i][j];
            }
            else {
                cout << myArray[i][j] << ",";
            }
        }
        if (i == rows - 1){
            cout << "}";
        }
        else {
            cout << "}, ";
        }
    }
    cout << " }" << endl;

    return 0;
}