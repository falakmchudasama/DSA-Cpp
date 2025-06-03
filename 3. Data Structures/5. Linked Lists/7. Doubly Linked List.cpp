#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* previous;
    Node(int val) : data(val), next(NULL), previous(NULL) {}
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(NULL) {}

    void insertTail(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->previous = temp;
    }

    void insertHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        if (head != NULL) {
            head->previous = newNode;
        }
        head = newNode;
    }

    int length() {
        Node* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void insertAtK(int position, int value) {
        Node* newNode = new Node(value);
        int size = length();
        if (position <= size) {
            Node* temp = head;
            if (position == 0) {
                newNode->next = head;
                if (head != NULL) {
                    head->previous = newNode;
                }
                head = newNode;
            } else {
                for (int i = 0; i < position - 1; i++) {
                    temp = temp->next;
                }
                newNode->previous = temp;
                newNode->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->previous = newNode;
                }
                temp->next = newNode;
            }
        }
    }

    void deleteTail() {
        if (head == NULL) {
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        if (temp->previous != NULL) {
            temp->previous->next = NULL;
        } else {
            head = NULL;
        }
        delete temp;
    }

    void deleteHead(){
        Node* temp = head;
        head = head->next;
        head->previous = NULL;
        delete temp;
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList head;
    head.insertTail(0);
    head.insertTail(1);
    head.insertTail(2);
    head.insertTail(3);
    head.insertTail(4);
    head.insertAtK(0,-1);
    head.deleteTail();
    head.deleteHead();
    head.print();
    return 0;
}