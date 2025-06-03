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

Node* LCA(Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL) {
        return root;
    }
    if (left == NULL && right == NULL) {
        return NULL;
    }
    if (left != NULL && right == NULL) {
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right, n1,n2);
}

int FindDistance(Node* root, int k, int dist){
    if (root == NULL) {
        return -1;
    }
    if (root->data == k) {
        return dist;
    }

    int left = FindDistance(root->left, k, dist+1);
    if (left != -1) {
        return left;
    }
    return FindDistance(root->right, k, dist+1);
}

int DistBetNodes(Node* root, int n1, int n2) {
    Node* lca = LCA(root, n1, n2);

    int d1 = FindDistance(lca, n1, 0);
    int d2 = FindDistance(lca, n2, 0);

    return d1+d2;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << DistBetNodes(root,4,3);
    return 0;
}