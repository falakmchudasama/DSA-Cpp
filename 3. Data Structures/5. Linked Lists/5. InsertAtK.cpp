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
    void insertAt(int position, int k){
        if(head != NULL){
            Node* temp = head;
            Node* nodeToInsert = new Node(k);
            if(position == 0){
                nodeToInsert->next = head;
                head = nodeToInsert;
                return;
            }
            else{
                int count = 1;
                while(count < position){
                    temp = temp->next;
                    count++;
                }
                nodeToInsert->next = temp->next;
                temp->next = nodeToInsert;
            }
        }
    }
};

int main(){
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.print();
    list.insertAt(4,999);
    list.print();
    return 0;
}