#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

bool isBalanced(Node* root, int* height) {
    if (root == nullptr) {
        *height = 0;
        return true;
    }

    int lh = 0;
    int rh = 0;

    if (isBalanced(root->left, &lh) == false) {
        return false;
    }

    if (isBalanced(root->right, &rh) == false) {
        return false;
    }

    *height = max(lh, rh) + 1;

    if (abs(lh - rh) <= 1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int h = 0;
    bool result = isBalanced(root, &h);
    cout << result << endl;

    // Don't forget to free the memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
