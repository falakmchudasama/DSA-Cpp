#include <iostream>
#include <array>
using namespace std;

// Function to check if a character is present in the given array and find its position.
void function(array<char,3> Array, char character){
    bool presence = false; // Initialize a boolean variable to track the presence of the character.
    // Loop through the array to search for the character.
    for (int i = 0; i < Array.size(); i++){
        if (Array[i] == character){
            presence = true; // Set presence to true if the character is found.
            cout<<"Character is: "<<character<<endl;
            cout<<"And is at the position: "<<(i+1)<<endl; // Print the position (index + 1).
            break; // Exit the loop once the character is found.
        }
    }
    // Check if the character was not found and provide a message.
    if (presence == false){
        cout<<"The character is not in the Array"<<endl;
    }
}
int main(){
    array<char,3> myArray = {'L','O','Y'};
    char character = 'L';
    function(myArray, character); // Call the function to search for the character.
    return 0;
}