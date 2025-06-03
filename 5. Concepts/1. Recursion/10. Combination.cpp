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

int factorial(int n){
    if (n == 0){
        return 1;
    }
    return factorial(n - 1) * n;
}

// Combination formula using factorial function
int nCr(int n, int r){
    int num = factorial(n);
    int den = factorial(r) * factorial(n-r);

    return num / den;
}

// Complete recursive function for combination
int NCR(int n, int r){
    if (n == r || r == 0){
        return 1;
    }
    return NCR(n-1, r-1) + NCR(n-1,r);
}

int main(){
    int n = 4;
    int r = 2;
    cout << nCr(n, r) << endl;
    cout << NCR(n, r) << endl;
    return 0;
}