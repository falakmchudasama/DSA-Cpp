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

// Bubble Sort
// Time complexity : O(n^2) (for worst and avg case) and O(n) (for best case)
// Space complexity : O(1) (all cases)

/* This sorting algorithm is named 'Bubble sorting' cause just like the bigger bubbles
in this algorithm, the greater numbers always come up to the top of the array.
*/
void bubbleSort(int array[], int n) {
    int counter = 1;
    while(counter < n){
        for(int i = 0; i < (n-counter); i++){
            if(array[i] > array[i+1]){
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
        counter++;
    }
}

int main() {
    int size = 5;
    int arr[] = {14, 9, 17, 2, 7};

    bubbleSort(arr, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}