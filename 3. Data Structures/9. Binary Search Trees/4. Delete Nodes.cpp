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

bool search(Node* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(root->data > key){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

Node* findInorderSuccessor(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int toDelete){
    if(!search(root, toDelete)){
        return NULL;
    }
    if(root->data > toDelete){
        root->left = deleteNode(root->left, toDelete);
    }
    else if(root->data < toDelete){
        root->right = deleteNode(root->right, toDelete);
    }
    else{
        // Case 1 : leaf node
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        // Case 2 : single child
        else if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL){
            return root->left;
        }
        else{
            Node* IS = findInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = deleteNode(root->right, IS->data);
        }
    }
}

int main(){
    int size = 9;
    int nodes[] = {5,7,9,6,3,2,1,4,8};
    Node* root = new Node( nodes[0] );
    for(int i = 1; i < 9; i++){
        root = buildBST(root, nodes[i]);
    }

    int del = 4;

    deleteNode(root, 8);
    printIn(root);
    return 0;
}