#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

struct Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(NULL) {}
    
    void insertTail(int value){
        Node* NewNode = new Node(value);
        if(head == NULL){
            head = NewNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp -> next;
        }
        temp->next = NewNode;
    }
    void insertHead(int value){
        Node* NewNode = new Node(value);
        NewNode->next = head;
        head = NewNode;
    }
    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    LinkedList head;
    head.insertHead(0);
    head.insertTail(1);
    head.insertTail(2);
    head.insertTail(3);
    head.insertTail(4);
    head.print();

    return 0;
}