#include <iostream>
#include <array>
using namespace std;

// Function to find the largest element in an array.
int largest(array<int,6> myArray){
    int largest_element = myArray[0]; // Assume the first element is the largest.
    // Loop through the array to find the largest element.
    for (int i = 0; i < myArray.size(); i++){
        if (myArray[i] > largest_element){
            largest_element = myArray[i]; // Update largest_element if a larger element is found.
        }
    }
    return largest_element; // Return the largest element.
}

// Function to find the smallest element in an array.
int smallest(array<int,6> myArray){
    int smallest_element = myArray[0]; // Assume the first element is the smallest.
    // Loop through the array to find the smallest element.
    for (int i = 0; i < myArray.size(); i++){
        if (myArray[i] < smallest_element){
            smallest_element = myArray[i]; // Update smallest_element if a smaller element is found.
        }
    }
    return smallest_element; // Return the smallest element.
}
int main(){
    array<int,6> Array = {9,-3,4,7,5,-6};
    cout<<"Largest element in the array is: "<<largest(Array)<<endl; // Print the largest element.
    cout<<"Smallest element in the array is: "<<smallest(Array)<<endl; // Print the smallest element.
    return 0;
}