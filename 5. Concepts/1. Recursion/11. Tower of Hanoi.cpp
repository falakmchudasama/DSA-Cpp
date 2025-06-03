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

// Tower of Hanoi
void TOH(int n, char source, char auxillary, char destination){
    if (n > 0){
        TOH(n - 1, source, destination, auxillary);
        cout << "From " << source << " to " << destination << endl;
        TOH(n - 1, auxillary, source, destination);
    }
}

int main(){
    int noOfDics = 3;
    char source = 'A';
    char auxillary = 'B';
    char destination = 'C';
    TOH(noOfDics, source, auxillary, destination);
    return 0;
}