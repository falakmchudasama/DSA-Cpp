#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Node structure for a binary tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to replace each node's value with the sum of its left and right subtrees
void sumReplace(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    // Recursively process left and right subtrees
    sumReplace(root->left);
    sumReplace(root->right);
    // Update the current node's value with the sum of left and right subtree values
    if (root->left != NULL) {
        root->data += root->left->data;
    }
    if (root->right != NULL) {
        root->data += root->right->data;
    }
}

// Function to perform in-order traversal of a binary tree and print the node values
void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    // Recursively process left subtree
    inOrderTraversal(root->left);
    // Print the current node's value
    std::cout << root->data << " ";
    // Recursively process right subtree
    inOrderTraversal(root->right);
}

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Print the original tree
    cout << "Original Tree: ";
    inOrderTraversal(root);
    cout << endl;

    // Replace node values with the sum of left and right subtrees
    sumReplace(root);

    // Print the tree after the sum replacement
    cout << "In-order Traversal after Sum Replacement: ";
    inOrderTraversal(root);

    cout << endl;
    return 0;
}