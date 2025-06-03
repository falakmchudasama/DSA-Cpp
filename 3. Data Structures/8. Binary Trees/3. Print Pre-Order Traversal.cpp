#include <iostream>

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize the node
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to perform pre-order traversal of a binary tree
void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Process the current node
    std::cout << root->data << " ";

    // Traverse the left subtree
    preOrderTraversal(root->left);

    // Traverse the right subtree
    preOrderTraversal(root->right);
}

// Example usage
int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Print the binary tree in pre-order traversal
    std::cout << "Pre-order Traversal: ";
    preOrderTraversal(root);

    return 0;
}
