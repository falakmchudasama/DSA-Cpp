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

// Tree recursion
void function(int n){
    if(n > 0){
        cout << n << " ";
        function(n - 1);
        function(n - 1);
    }
}

int main(){
    int x = 3;
    function(x);
    return 0;
}