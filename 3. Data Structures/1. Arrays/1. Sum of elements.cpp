#include <iostream>
#include <array>
using namespace std;

// Function to calculate the sum of elements in an array.
int sum_of_elements(array<int,6> myArray){
    int sum = 0; // Initialize a variable to store the sum.
    // Loop through the array and add each element to the sum.
    for (int i = 0; i < myArray.size(); i++){
        sum = sum + myArray[i];
    }
    return sum; // Return the sum.
}
int main(){
    array<int,6> Array = {3,3,3,3,3,3};
    cout<<sum_of_elements(Array)<<endl; // Print the sum of elements in the array.
    return 0;
}