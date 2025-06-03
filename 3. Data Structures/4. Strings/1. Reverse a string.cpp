#include <iostream>

// Function to reverse a string
std::string reverseString(const std::string& str) {
    std::string reversed;
    for (int i = str.length() - 1; i >= 0; --i) {
        reversed += str[i];
    }
    return reversed;
}

int main() {
    std::string original = "Hello, World!";
    std::string reversed = reverseString(original);
    
    std::cout << "Original: " << original << std::endl;
    std::cout << "Reversed: " << reversed << std::endl;

    return 0;
}