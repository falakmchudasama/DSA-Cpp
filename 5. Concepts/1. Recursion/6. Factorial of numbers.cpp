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
    else {
        return factorial(n - 1) * n;
    }
}

int main(){
    int x = 5;
    cout << factorial(5) << endl;
    return 0;
}