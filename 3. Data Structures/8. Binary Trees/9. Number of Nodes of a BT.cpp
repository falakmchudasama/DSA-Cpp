#include <iostream>
#include <queue>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to count the number of nodes in the binary tree
int countNodes(Node* root) {
    // If the root is null, the tree is empty, so return 0 nodes
    if (root == NULL) {
        return 0;
    }

    // Recursively count nodes in the left and right subtrees,
    // and add 1 for the current node
    return countNodes(root->left) + countNodes(root->right) + 1;
}

// Main function to test the countNodes function
int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    // Print the number of nodes in the binary tree
    cout << "Number of nodes in the tree: " << countNodes(root) << endl;

    // Deallocate memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
