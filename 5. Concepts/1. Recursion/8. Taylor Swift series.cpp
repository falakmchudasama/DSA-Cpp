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
    else{
        return factorial(n - 1) * n;
    }
}

double exponent(double x, int n){
    if (n == 0){
        return 1;
    }
    else{
        if (n % 2 == 0){
            return exponent(x * x, n / 2);
        }
        else{
            return x * exponent(x * x, (n-1) / 2);
        }
    }
}

// O(n^2)
double taylorSwiftSeries(double a, int b){
    if(b == 0){
        return 1;
    }
    else{
        return taylorSwiftSeries(a,b-1) + (exponent(a, b) / factorial(b));
    }
}

// O(n)
double eTaylorSwiftSeries(double a, int b){
    static double S = 1;
    if (b == 0){
        return S;
    }
    S = 1 + a * S / b ;
    return eTaylorSwiftSeries(a, b - 1);
}

int main(){
    int x = 2;
    int n = 12;
    cout << eTaylorSwiftSeries(x, n) << endl;
    cout << taylorSwiftSeries(x, n) << endl;
    return 0;
}