#include <iostream>
using namespace std;

// Define the Node structure for the binary tree
struct Node {
    int data;
    Node *right;
    Node *left;

    // Constructor to initialize Node with a given value
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to search for an element in the inorder array
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val) {
            return i; // Return the index if the value is found in the array
        }
    }
    return -1; // Return -1 if the value is not found in the array
}

// Recursive function to build the binary tree using postorder and inorder traversals
Node *buildTree(int postorder[], int inorder[], int start, int end) {
    static int idx = 4; // Static variable to keep track of the current index in the postorder array
    if (start > end) {
        return NULL; // Base case: return null for an empty subtree
    }

    int val = postorder[idx];
    idx--;
    Node *curr = new Node(val); // Create a new Node with the current value

    if (start == end) {
        return curr; // Base case: return the node for a leaf element
    }

    // Find the position of the current element in the inorder array
    int pos = search(inorder, start, end, val);

    // Recursively build the right and left subtrees
    curr->right = buildTree(postorder, inorder, pos + 1, end);
    curr->left = buildTree(postorder, inorder, start, pos - 1);

    return curr; // Return the current node
}

// Function to perform in-order traversal of the binary tree and print the elements
void inorderPrint(Node *root) {
    if (root == NULL) {
        return; // Base case: return for an empty tree or leaf node
    }

    // Recursively print the left subtree, current node, and then the right subtree
    inorderPrint(root->left);
    cout << root->data << " "; // Print the current node's data
    inorderPrint(root->right);
}

// Main function
int main() {
    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};

    // Build the binary tree
    Node *root = buildTree(postorder, inorder, 0, 4);

    // Perform in-order traversal and print the elements
    inorderPrint(root);

    return 0;
}
