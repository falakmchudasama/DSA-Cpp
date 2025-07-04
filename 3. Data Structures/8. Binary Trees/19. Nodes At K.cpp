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

// Case 1
void printSubtreeNodes(Node* root, int k) {
    if (root == NULL) {
        return;
    }
    if (k == 0) {
        cout << root->data << " ";
        return;
    }

    printSubtreeNodes(root->left, k - 1);
    printSubtreeNodes(root->right, k - 1);
}

// Case 2
int printNodesAtK(Node* root, Node* target, int k) {
    if (root == NULL) {
        return -1;
    }
    if (root == target) {
        printSubtreeNodes(root, k);
        return 0;
    }
    int dl = printNodesAtK(root->left, target, k);
    if (dl != -1) {
        if (dl + 1 == k) {
            cout << root->data << " ";
        } else {
            printSubtreeNodes(root->right, k - dl - 2);
        }
        return 1 + dl;
    }
    int dr = printNodesAtK(root->right, target, k);
    if (dr != -1) {
        if (dr + 1 == k) {
            cout << root->data << " ";
        } else {
            printSubtreeNodes(root->left, k - dr - 2);
        }
        return 1 + dr;
    }
    return -1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    printNodesAtK(root, root->left, 3);
    return 0;
}
