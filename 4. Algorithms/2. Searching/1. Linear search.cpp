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

// Linear search
// Time complexity : O(n) (for worst case and avg case) and O(1) (for best case)
// Space complexity : O(1)

int linearSearch(int array[], int n, int key){
    for(int i = 0; i < n; i++){
        if(array[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int size = 7; // Thala for a reason
    int arr[size] = {1,2,3,4,5,6,7};
    int result;

    result = linearSearch(arr, size, 7);
    cout << result << endl;

    return 0;
}