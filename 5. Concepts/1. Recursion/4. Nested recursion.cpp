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

long long int function(long long int n){
    if (n > 100){
        return n - 10;
    }
    else {
        function(function(n + 11));
    }
}

int main(){
    long long int x = 95;
    cout << function(x) << endl;
    return 0;
}