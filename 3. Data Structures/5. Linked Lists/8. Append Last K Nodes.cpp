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
    Node(int value) : data(value), next(NULL) {}
};

class LinkedList {
private:
    Node* head;
public: 
    LinkedList() : head(NULL) {}

    void insert(int value){
        Node* newNode = new Node(value);
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void print(){
        if(head != NULL){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

    void reverse(){
        if(head != NULL && head -> next != NULL){
            Node* temp = head;
            Node* Current = temp;
            Node* Previous = NULL;
            Node* Next = NULL;
            while(Current != NULL){
                Next = Current->next;
                Current->next = Previous;
                Previous = Current;
                Current = Next;
            }
            head = Previous;
        }
    }
    int size(){
        int count = 0;
        Node* temp = head;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    void appendK(int k){
        Node* temp = head;
        Node* newTail;
        Node* newHead;
        int l = size();

        if(k == 0){
            return;
        }

        k = k % l;
        for(int i = 0; i < l - k - 1; i++){
            temp = temp->next;
        }
        newHead = temp->next;
        newTail = temp;

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head;
        head = newHead;
        newTail->next = NULL;
    }
};

int main(){
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.appendK(1);
    list.print();
    return 0;
}