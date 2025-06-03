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


// Print first, then call
// Tail recursion
void fun1(int n){
    if(n > 0){
        cout << n << " ";
        fun1(n-1);
    }
}

// Call first, then print
// Head recursion
void fun2(int n){
    if(n > 0){
        fun2(n-1);
        cout << n << " ";
    }
}

int main(){
    int x = 3;
    fun1(x);
    cout << endl;
    fun2(x);
    cout << endl;
    return 0;
}