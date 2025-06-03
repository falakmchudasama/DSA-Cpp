#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

int maxPathSumUntil(Node* root, int &ans) {
    if (root == NULL) {
        return 0;
    }
    int left = maxPathSumUntil(root->left, ans);
    int right = maxPathSumUntil(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));
    ans = max(ans, nodeMax);

    int singlePathSum = max(root->data, max(root->data + left, root->data + right));
    return singlePathSum;
}

int maxPathSum(Node* root) {
    int ans = INT_MIN;
    maxPathSumUntil(root,ans);
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    int n = maxPathSum(root);
    cout << n << endl;

    return 0;
}
