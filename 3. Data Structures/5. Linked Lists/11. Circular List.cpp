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

class Linked {
private:
    Node* head;

public:
    Linked() : head(NULL) {}

    void print() {
        Node* temp = head;
        Node* start = head;
        if (head->next == NULL) {
            cout << head->data << endl;
            return;
        }
        cout << temp->data << " -> ";
        temp = temp->next;
        while (temp != start) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << head->data << endl;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        } else if (head->next == NULL) {
            head->next = newNode;
            newNode->next = head;
            return;
        }
        Node* start = head;
        Node* temp = head;
        while (temp->next != start) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void deleteHead() {
        if (head == NULL) {
            return; // No nodes to delete
        } else if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        Node* start = head;
        while (temp->next != start) {
            temp = temp->next;
        }
        Node* del = head;
        head = head->next;
        temp->next = head;
        delete del;
    }

    void deleteTail() {
        if (head == NULL) {
            return; // No nodes to delete
        } else if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        Node* start = head;
        while (temp->next->next != start) {
            temp = temp->next;
        }
        Node* del = temp->next;
        temp->next = head;
        delete del;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        Node* start = head;
        while (temp != start) {
            temp = temp->next;
            count++;
        }
        return count;
    }
};

int main() {
    Linked list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(7);
    list.deleteHead();
    list.deleteTail();
    list.print();
    return 0;
}
