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

int function(int n){
    if (n > 0){
        return function(n - 1) + n;
    }
}

int main(){
    int x = 7;
    cout << function(x) << endl;
    return 0;
}