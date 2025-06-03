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

// int exponent(int m, int n){
//     if (n <= 0){
//         return 1;
//     }
//     else {
//         return exponent(m,n-1) * m;
//     }
//     cout << "Normal function was called" << endl;
// }


// Memory and Space efficient function
int exponent(int m, int n){
    if (n <= 0){
        return 1;
    }
    else {
        if (n % 2 == 0){
            return exponent(m * m, n / 2);
            cout << "Better one was called" << endl;
        }
        else {
            return exponent(m * m, (n- 1) / 2) * m;
        }
    }
}

int main(){
    int index = 5;
    int power = 3;
    cout << exponent(index, power) << endl;
    return 0;
}