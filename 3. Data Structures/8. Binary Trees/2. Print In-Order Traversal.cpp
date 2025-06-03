#include <iostream>

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize the node
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to perform in-order traversal of a binary tree
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Traverse the left subtree
    inOrderTraversal(root->left);

    // Process the current node
    std::cout << root->data << " ";

    // Traverse the right subtree
    inOrderTraversal(root->right);
}

// Example usage
int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Print the binary tree in in-order traversal
    std::cout << "In-order Traversal: ";
    inOrderTraversal(root);

    return 0;
}
