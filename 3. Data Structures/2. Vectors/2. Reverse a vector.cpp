#include <iostream>
#include <vector>
using namespace std;

// Function to reverse the elements of a vector.
void function(vector<int> Vector){
    vector<int> reversed_vector; // Create a new vector to store reversed elements.
    int element; // Initialize a variable to temporarily hold each element.
    // Loop through the input vector in reverse order.
    for (int i = (Vector.size()-1); i >= 0; i--){
        element = Vector[i]; // Get the element at the current index.
        reversed_vector.push_back(element); // Add the element to the reversed vector.
    }
    // Display the reversed vector.
    cout<<"The reversed vector is: {";
    for(int i = 0; i < reversed_vector.size(); i++){
        if (i == reversed_vector.size()-1){
            cout<<reversed_vector[i];
        }
        else{
            cout<<reversed_vector[i]<<",";
        }
    }
    cout<<"}"<<endl;
}
int main(){
    vector<int> MyVector = {9,3,6,7,9};
    function(MyVector); // Call the function to reverse the vector.
    return 0;
}