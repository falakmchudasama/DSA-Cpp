#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cctype>

#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void printIn(Node* root) {
    if (root == nullptr) {
        return;
    }
    printIn(root->left);
    cout << root->data << " ";
    printIn(root->right);
}

void printPre(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    printPre(root->left);
    printPre(root->right);
}

Node* buildBST(Node* root, int value) {
    if (root == nullptr) {
        Node* newNode = new Node(value);
        return newNode;
    }
    if (root->data > value) {
        root->left = buildBST(root->left, value);
    }
    if (root->data < value) {
        root->right = buildBST(root->right, value);
    }
    return root;
}

bool isValid(Node* root, int min, int max) {
    if (root == nullptr) {
        return true;
    }
    if ((min != INT_MIN && root->data <= min) || (max != INT_MAX && root->data >= max)) {
        return false;
    }
    return isValid(root->left, min, root->data) && isValid(root->right, root->data, max);
}

Node* mirror(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    Node* mLeft = mirror(root->left);
    Node* mRight = mirror(root->right);

    Node* mRoot = new Node(root->data);
    mRoot->left = mRight;
    mRoot->right = mLeft;

    return mRoot;
}

int main() {
    int size = 9;
    int nodes[] = {5, 7, 9, 6, 3, 2, 1, 4, 8};
    Node* root = new Node(nodes[0]);
    for (int i = 1; i < 9; i++) {
        root = buildBST(root, nodes[i]);
    }

    Node* mirrorRoot = mirror(root);
    printIn(mirrorRoot);
    cout << endl;
    cout << isValid(root, INT_MIN, INT_MAX) << endl;
    cout << isValid(mirrorRoot, INT_MIN, INT_MAX) << endl;

    // Deallocate memory to prevent memory leaks
    delete root;
    delete mirrorRoot;
    return 0;
}