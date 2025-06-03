#include <iostream>
#include <algorithm>
using namespace std;

// Node structure for a binary tree
struct Node {
    int data;       
    Node* left;     
    Node* right;    

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to calculate the diameter of a binary tree
int calcDiameter(Node* root, int* height) {
    // Base case: If the tree is empty, set height to 0 and return 0
    if (root == nullptr) {
        *height = 0;
        return 0;
    }

    // Variables to store the height of left and right subtrees
    int lh = 0, rh = 0;

    // Recursive calls to calculate diameter of left and right subtrees
    int ldiameter = calcDiameter(root->left, &lh);
    int rdiameter = calcDiameter(root->right, &rh);

    // Calculate the diameter passing through the current root
    int currentdiameter = lh + rh + 1;

    // Update the height of the current subtree
    *height = max(lh, rh) + 1; 

    // Return the maximum of the diameters calculated so far
    return max(currentdiameter, max(ldiameter, rdiameter));
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    int height = 0;
    cout << calcDiameter(root, &height) << endl;

    return 0;
}
