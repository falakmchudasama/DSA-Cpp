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

// Insertion Sort
// Time complexity : O(n^2) (for worst and avg cases) and O(n) (for best case)
// Space complexity : O(1) (for all cases)

void insertionSort(int array[], int n) {
    for(int i = 1; i < n; i++){
        int current = array[i];
        int j = i-1;
        while(array[j] > current && j >= 0){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = current;
    }
}

int main() {
    int size = 5;
    int arr[] = {14, 9, 17, 2, 7};

    insertionSort(arr, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}