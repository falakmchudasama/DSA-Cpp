#include <iostream>
#include <vector>
using namespace std;

// Function to reverse a vector and print it in curly braces
void function(vector<int> myVector){
    // Create a new vector to store the reversed elements
    vector<int> inverted_vector = {}
    // Loop through the original vector in reverse order
    for(int i = (myVector.size()-1); i >= 0; i--){
        // Add each element to the new vector in reverse order
        inverted_vector.push_back(myVector[i]);
    }
    // Print the reversed vector in curly braces
    cout << "{";
    for (int i = 0; i < inverted_vector.size(); i++){
        if (i == inverted_vector.size()-1){
            cout << inverted_vector[i];
        }
        else {
            cout << inverted_vector[i] << ",";
        }
    }
    cout << "}" << endl;
}

int main(){
    // Create a vector named MyVector and initialize it with values
    vector<int> MyVector = {1,2,3,4,5,6,7,8,9};
    // Call the function to reverse and print the vector
    function(MyVector);
    return 0;
}