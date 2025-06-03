#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

// We are implementing Linked List cause
// 1. We don't have to worry about the fixed size of the array that we initialise
// 2. It is memory efficient as it does not require allocation of the extra memory

// LIFO rocks, FIFO sucks
struct Node {
public: 
    int data;
    Node* next;
    Node* previous;
    Node(int value) : data(value), next(NULL), previous(NULL) {}
};

class Stack {
private:
    Node* Top;
    Node* head;
    int maxValue = 0;
public:
    Stack(){
        Top = NULL;
        head = NULL;
    }
    void push(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            Top = newNode;
        } else {
            newNode->previous = Top;
            Top->next = newNode;
            Top = newNode;
        }
        if (value >= maxValue){
            maxValue = value;
        }
    }
    void pop(){
        if(Top == NULL){
            cout << "Stack underflow" << endl;
            return;
        }
        Top = Top->previous;
    }
    bool empty(){
        return Top == NULL;
    }
    int top(){
        if(Top == NULL){
            cout << "Stack underflow" << endl;
            return -1;
        }
        return Top->data;
    }
    void clear(){
        Top = NULL;
        head = NULL;
        maxValue = 0;
    }
    int getMax(){
        return maxValue;
    }
    void print(){
        Node* temp = Top;
        if(Top == NULL){
            cout << "Stack underflow" << endl;
            return;
        }
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->previous;
        }
        cout << endl;
    }
};

int main(){
    
    return 0;
}