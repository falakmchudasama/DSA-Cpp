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

// Count Sort
// Time Complexity : O(n) or O(Ai) (for worst case) and O(n) (for best and avg cases) | where Ai is the size of the count vector
// Space Complexity : O(n) (for all cases)

void countSort(int array[], int n){
    int k = array[0];
    for(int i = 0; i < n; i++){
        k = max(k,array[i]);
    }
    vector<int> count(k+1,0);
    for(int i = 0; i < n; i++){
        count[array[i]]++;
    }
    for(int i = 1; i <= k; i++){
        count[i] += count[i-1]; 
    }
    vector<int> outPut(n);
    for(int i = n-1; i >= 0; i--){
        outPut[--count[array[i]]] = array[i];
    }
    for(int i = 0; i < n; i++){
        array[i] = outPut[i];
    }
}

int main(){
    int size = 9;
    int arr[size] = {1,3,2,3,4,1,6,4,3};

    countSort(arr,size);

    for(int i = 0; i < 9; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}