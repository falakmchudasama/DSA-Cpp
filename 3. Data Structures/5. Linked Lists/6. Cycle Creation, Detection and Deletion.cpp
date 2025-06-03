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

    // Hare and tortoise algorithm
    void makeCycle(int position) {
        Node* temp = head;
        Node* startNode;
        int count = 1;
        while (temp->next != NULL) {
            if (count == position) {
                startNode = temp;
            }
            temp = temp->next;
            count++;
        }
        temp->next = startNode;
    }

    bool detectCycle() {
        Node* hare = head;
        Node* tortoise = head;
        while (hare != NULL && hare->next != NULL) {
            hare = hare->next->next;
            tortoise = tortoise->next;
            if (hare == tortoise) {
                return true;
            }
        }
        return false;
    }

    void removeCycle() {
        if (detectCycle()) {
            Node* tortoise = head;
            Node* hare = head;

            hare = hare->next->next;
            tortoise = tortoise->next;
            while (hare != tortoise) {
                hare = hare->next->next;
                tortoise = tortoise->next;
            }
            hare = head;
            while (tortoise->next != hare->next) {
                tortoise = tortoise->next;
                hare = hare->next;
            }
            tortoise->next = NULL;
        }
    }
};
int main() {
    LinkedList head;
    head.insertHead(0);
    head.insertTail(1);
    head.insertTail(2);
    head.insertTail(3);
    head.insertTail(4);
    head.makeCycle(4);
    cout << head.detectCycle() << endl;
    head.removeCycle();
    cout << head.detectCycle() << endl;
    head.print();
    return 0;
}