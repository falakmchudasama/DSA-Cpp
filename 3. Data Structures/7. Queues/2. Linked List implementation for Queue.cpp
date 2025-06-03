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

// FIFO rocks, LIFO sucks
struct Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

class Queue {
private : 
    Node* front;
    Node* back;
public:
    Queue() {
        front = NULL;
        back = NULL;
    }
    void enque(int value){
        Node* newNode = new Node(value);
        if(front == NULL){
            front = newNode;
            back = newNode;
            return;
        }
        back->next = newNode;
        back = newNode;
    }
    void deque(){
        if (front == NULL){
            cout << "Queue underflow" << endl;
            return;
        }
        Node* toDelete = front;
        front = front->next;
        delete toDelete;
    }
    int peek(){
        if (front == NULL){
            cout << "Queue underflow" << endl;
            return -1;
        }
        return front->data;
    }
    bool empty(){
        return front == NULL;
    }
    void clear(){
        Node* nodeToDelete = front;
        front = NULL;
        back = NULL;
        delete nodeToDelete;
    }
    void print(){
        if (front == NULL){
            cout << "Queue underflow" << endl;
            return;
        }
        Node* temp = front;
        while(temp != back->next){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Queue q;
    
    return 0;
}