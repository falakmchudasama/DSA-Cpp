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

struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(NULL), next(NULL) {};
};

class DoublyLinked{
private:
    Node* head;
public:
    DoublyLinked() : head(NULL) {}

    void insertTail(int value){
        Node* newNode = new Node(value);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void insertHead(int value){
        Node* newNode = new Node(value);
        if(head == NULL){
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = NULL;
        head = newNode;
    }
    void print(){
        Node* temp = head;
        if(head == NULL){
            return;
        }
        cout << "NULL <- ";
        while(temp->next != NULL){
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << temp->data << " -> NULL" << endl;
    }
    int length(){
        Node* temp = head;
        int size = 0;
        while(temp != NULL){
            temp = temp->next;
            size++;
        }
        return size;
    }
    void insertAtK(int value, int position){
        int size = length();
        int count = position;
        if(head == NULL || position > size){
            return;
        }
        else if(count == 0){
            insertHead(value);
            return;
        }
        else if (count == size){
            insertTail(value);
            return;
        }
        else{
            Node* newNode = new Node(value);
            Node* temp = head;
            while(count > 0){
                temp = temp->next;
                count--;
            }
            Node* temp2 = temp->prev;
            temp2->next = newNode;
            newNode->prev = temp2;
            newNode->next = temp;
            temp->prev = newNode;
        }
    }
    void insertSort(int value){
        Node* temp = head;
        Node* previous = NULL;
        while(temp != NULL && temp->data <= value){
            previous = temp;
            temp = temp->next;
        }
        if(previous == NULL){
            insertHead(value);
        }
        else if(temp == NULL || temp->next == NULL){
            insertTail(value);
        }
        else{
            Node* newNode = new Node(value);
            temp->prev = newNode;
            newNode->next = temp;
            newNode->prev = previous;
            previous->next = newNode;
        }
    }
};

int main(){
    DoublyLinked list;
    list.insertTail(8);
    list.insertTail(11);
    list.insertTail(15);
    list.insertTail(18);
    list.insertTail(19);
    list.insertTail(21);
    list.insertTail(26);
    list.insertTail(38);
    list.insertSort(66);
    list.print();
    return 0;
}