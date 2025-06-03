#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void InsertAtTail(Node* &head, int value){
    Node* n = new Node(value);
    if (head == NULL){
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void InsertAtHead(Node* &head, int value){
    Node* n = new Node(value);
    n->next = head;
    head = n;
}

void PrintList(Node* head){
    if(head == NULL){
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    Node* head = NULL;
    InsertAtHead(head, 0);
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    InsertAtTail(head, 6);
    InsertAtTail(head, 7);
    InsertAtTail(head, 8);
    PrintList(head);
    return 0;
}