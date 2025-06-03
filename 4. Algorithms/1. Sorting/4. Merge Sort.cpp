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

// Merge Sort
// Time complexity : O(n log n) (for all cases)
// Space complexity : O(n) (for all cases)

void merge(int array[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a1[n1];
    int a2[n2];

    for (int i = 0; i < n1; i++) {
        a1[i] = array[l + i];
    }
    for (int j = 0; j < n2; j++) {
        a2[j] = array[mid + 1 + j];
    }

    int a = 0;
    int b = 0;
    int c = l;
    while (a < n1 && b < n2) {
        if (a1[a] < a2[b]) {
            array[c] = a1[a];
            c++;
            a++;
        } else {
            array[c] = a2[b];
            c++;
            b++;
        }
    }
    while (a < n1) {
        array[c] = a1[a];
        c++;
        a++;
    }
    while (b < n2) {
        array[c] = a2[b];
        c++;
        b++;
    }
}

void mergeSort(int array[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;

        mergeSort(array, l, mid);
        mergeSort(array, mid + 1, r);
        merge(array, l, mid, r);
    }
}

int main() {
    int arr[] = {8, 3, 7, 4, 6, 9, 5, 1, 2};
    mergeSort(arr, 0, 8);
    for (int i = 0; i < 9; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}