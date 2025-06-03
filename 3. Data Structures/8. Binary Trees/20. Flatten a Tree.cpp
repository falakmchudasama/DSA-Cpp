#include <iostream>
using namespace std;

// Definition of a binary tree node
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Function to perform an in-order traversal of a binary tree
void InOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

// Function to flatten a binary tree
void flatten(Node* root) {
    // Base case: if the tree is empty or is already flattened
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }

    // If the left subtree is not empty, flatten it
    if (root->left != NULL) {
        flatten(root->left);

        // Store the right subtree in a temporary variable
        Node* temp = root->right;

        // Connect the left subtree as the new right subtree of the root
        root->right = root->left;
        root->left = NULL;

        // Move to the end of the newly formed right subtree and attach the original right subtree
        Node* tail = root->right;
        while(tail->right != NULL) {
            tail = tail->right;
        }
        tail->right = temp;

        // Flatten the remaining right subtree
        flatten(root->right);
    }
}

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // Display the original tree using in-order traversal
    cout << "Original Tree (In-order traversal): ";
    InOrderTraversal(root);
    cout << endl;

    // Flatten the tree
    flatten(root);

    // Display the flattened tree using in-order traversal
    cout << "Flattened Tree (In-order traversal): ";
    InOrderTraversal(root);

    return 0;
}
