#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to search for an element in the inorder array
int search(int inorder[], int start, int end, int current) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == current) {
            return i;
        }
    }
    return -1;
}

// Recursive function to build the binary tree
Node* buildTree(int preorder[], int inorder[], int start, int end) {
    static int idx = 0;
    if (start > end) {
        return nullptr; // Base case: return null for empty subtree
    }

    int current = preorder[idx];
    idx++;
    Node* node = new Node(current);

    if (start == end) {
        return node; // Base case: return the node for a leaf element
    }

    // Find the position of the current element in the inorder array
    int pos = search(inorder, start, end, current);

    // Recursively build the left and right subtrees
    node->left = buildTree(preorder, inorder, start, pos - 1);
    node->right = buildTree(preorder, inorder, pos + 1, end);

    return node;
}

// Function to perform in-order traversal of the binary tree
void inorderPrint(Node* root) {
    if (root == nullptr) {
        return;
    }
    // Recursively print the left subtree, current node, and then the right subtree
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    // Build the binary tree
    Node* root = buildTree(preorder, inorder, 0, 4);

    // Perform in-order traversal and print the elements
    inorderPrint(root);

    return 0;
}
