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

// Binary search
// Time complexity : O(log n) (for worst case and avg case) and O(1) (for best case)
// Space complexity : O(1)

int binarySearch(int array[], int n, int key){
    int start = 0;
    int end = n;
    while(start <= end){
        int mid = (start + end) / 2;

        if(array[mid] == key){
            return mid;
        }
        else if(array[mid] > key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}

int main(){
    int size = 7; // Thala for a reason
    int arr[size] = {1,2,3,4,5,6,7};
    int result;

    result = binarySearch(arr, size, 7);
    cout << result << endl;

    return 0;
}