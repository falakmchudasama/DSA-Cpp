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
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}

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
    }

    void insertHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void deletion(int val) {
        if (head == NULL) {
            return;
        }
        Node* temp = head;
        if (val == head->data) {
            head = head->next;
            delete temp;
        } else {
            while (temp->next != NULL && temp->next->data != val) {
                temp = temp->next;
            }
            if (temp->next != NULL) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            }
        }
    }

    // Iterative
    void reverse() {
        Node* previous = NULL;
        Node* current = head;
        Node* nxt;
        while (current != NULL) {
            nxt = current->next;
            current->next = previous;
            previous = current;
            current = nxt;
        }
        head = previous;
    }

    // Recursive
    void reverseRecursive() {
        head = reverse(head);
    }

private:
    Node* reverse(Node* current) {
        if (current == NULL || current->next == NULL) {
            return current;
        }
        Node* newHead = reverse(current->next);
        current->next->next = current;
        current->next = NULL;
        return newHead;
    }
};

int main() {
    LinkedList head;
    head.insertHead(0);
    head.insertTail(1);
    head.insertTail(2);
    head.insertTail(3);
    head.insertTail(4);
    head.print();
    return 0;
}