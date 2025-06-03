#include <iostream>

// Function to check if a string is a palindrome
bool isPalindrome(const std::string& str) {
    int length = str.length();
    for (int i = 0; i < length / 2; ++i) {
        if (str[i] != str[length - i - 1]) {
            return false; // Not a palindrome
        }
    }
    return true; // Palindrome
}

int main() {
    std::string palindrome = "madam";
    std::string notPalindrome = "hello";

    // Check if a string is a palindrome
    if (isPalindrome(palindrome)) {
        std::cout << palindrome << " is a palindrome." << std::endl;
    } else {
        std::cout << palindrome << " is not a palindrome." << std::endl;
    }

    if (isPalindrome(notPalindrome)) {
        std::cout << notPalindrome << " is a palindrome." << std::endl;
    } else {
        std::cout << notPalindrome << " is not a palindrome." << std::endl;
    }

    return 0;
}