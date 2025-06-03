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

// Excessive function
int fib(int n){
    if (n <= 1){
        return n;
    }
    return fib(n - 2) + fib(n - 1);
}

// Memorization
int F[15];
int mfib(int n){
    if (n <= 1){
        F[n] = n;
        return n;
    }
    else{
        if (F[n-2] == -1){
            F[n-2] = mfib(n-2);
        }
        if (F[n-1] == -1){
            F[n-1] = mfib(n-1);
        }
        return F[n-2] + F[n-1];
    }
}

int main(){
    int x = 12;
    for(int i = 0; i < 15; i++){
        F[i] = -1;
    }
    cout << mfib(x) << endl;
    return 0;
}