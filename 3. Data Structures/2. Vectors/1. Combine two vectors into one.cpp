#include <iostream>
#include <vector>
using namespace std;

// This function takes two vectors and calculates their element-wise sum.
void function(vector<int> v1, vector<int> v2){
    vector<int> result; // Create a vector to store the result.
    int sum = 0; // Initialize a variable to store the sum of elements.

    // Check if the input vectors have the same size.
    if (v1.size() != v2.size()){
        cout<<"Two vectors must have the same size :("<<endl;
    }
    else{
        // Loop through the vectors and calculate the sum of corresponding elements.
        for(int i = 0; i < v1.size(); i++){
            sum = (v1[i] + v2[i]);
            result.push_back(sum); // Add the sum to the result vector.
        }

        // Display the elements of the result vector.
        cout<<"The New Vector is: {";
        for (int i = 0; i < result.size(); i++){
            if (i == result.size()-1){
                cout<<result[i];
            }
            else{
                cout<<result[i]<<",";
            }
        }
        cout<<"}"<<endl;
    }
}

int main(){
    cout<<endl;
    vector<int> vector1 = {1,2,3,4,5,6};
    vector<int> vector2 = {6,5,4,3,2,1};
    function(vector1,vector2); // Call the function with two vectors.
    return 0;
}