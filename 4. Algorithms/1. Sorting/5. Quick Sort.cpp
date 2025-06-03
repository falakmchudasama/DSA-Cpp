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

// Quick Sort
// Time Complexity : O(n^2) (for worst case) and O(log n) (for best and avg cases)
// Space Complexity : O(n) (for worst case) and O(log n) (for avg and best cases)

void swap(int array[], int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    return;
}

int partition(int array[], int left, int right){
    int index = left - 1;
    int pivot = array[right];

    for(int i = left; i < right; i++){
        if(array[i] < pivot){
            index++;
            swap(array, index, i);
        }
    }

    swap(array, index+1, right);
    return index+1;
}

void quickSort(int array[], int left, int right){
    if(left < right){
        int pivot = partition(array, left, right);
        quickSort(array, left, pivot-1);
        quickSort(array, pivot+1, right);
    }
}

int main(){
    int size = 9;
    int arr[size] = {1,7,2,8,9,5,3,4,6};
    int right = size-1;
    int left = 0;

    quickSort(arr, left, right);

    for(int i = 0; i < 9; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}