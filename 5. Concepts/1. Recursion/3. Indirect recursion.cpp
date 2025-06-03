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

// Function prototype
void functionB(int n);

// Indirect recursion
void functionA(int n){
    if(n > 0){
        cout << n << " ";
        functionB(n - 1);
    }
}

void functionB(int n){
    if (n > 1){
        cout << n << " ";
        functionA(n / 2);
    }
}

int main(){
    int x = 20;
    functionA(x);
    return 0;
}