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

// Function to calculate the sum of all nodes in the binary tree
int sumNodes(Node* root) {
    // If the root is null, the tree is empty, so return 0
    if (root == NULL) {
        return 0;
    }

    // Recursively calculate the sum of nodes in the left and right subtrees,
    // and add the value of the current node
    return sumNodes(root->left) + sumNodes(root->right) + root->data;
}

// Main function to test the sumNodes function
int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    // Print the sum of all nodes in the binary tree
    cout << "Sum of all nodes in the tree: " << sumNodes(root) << endl;

    // Deallocate memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
