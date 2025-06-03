#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printIn(Node* root){
    if(root == NULL){
        return;
    }
    printIn(root->left);
    cout << root->data << " ";
    printIn(root->right);
}

void printPre(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    printPre(root->left);
    printPre(root->right);
}

Node* buildBST(Node* root,int value){
    if(root == NULL){
        Node* newNode = new Node(value);
        return newNode;
    }
    if(root->data > value){
        root->left = buildBST(root->left, value);
    }
    if(root->data < value){
        root->right = buildBST(root->right,value);
    }
    return root;
}

void printPath(Node* root, int leaf){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    if(root->data >= leaf){
        printPath(root->left, leaf);
    }
    if(root->data < leaf){
        printPath(root->right, leaf);
    }
}

int main(){
    int size = 9;
    int nodes[] = {5,7,9,6,3,2,1,4,8};
    Node* root = new Node( nodes[0] );
    for(int i = 1; i < 9; i++){
        root = buildBST(root, nodes[i]);
    }

    int leaf = 8;

    printPath(root, leaf);

    return 0;
}