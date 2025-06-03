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
    Node(int value) : data(value), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void print() {
        if (head != NULL) {
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

    void intersect(LinkedList& list2, int position) {
        Node* temp1 = head;
        Node* temp2 = list2.head;
        for (int i = 0; i < position && temp1 != NULL; i++) {
            temp1 = temp1->next;
        }
        while (temp2->next != NULL) {
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }

    int findIntersection(LinkedList& list) {
        int len1 = size();
        int len2 = list.size();
        int diff = abs(len1 - len2);

        Node* temp1 = head;
        Node* temp2 = list.head;

        if (len1 > len2) {
            for (int i = 0; i < diff; i++) {
                temp1 = temp1->next;
            }
        } else {
            for (int i = 0; i < diff; i++) {
                temp2 = temp2->next;
            }
        }

        while (temp1 != temp2 && temp1 != NULL && temp2 != NULL) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (temp1 == temp2) {
            return temp1->data;
        }
        return -1;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            count++;
        }
        return count;
    }
};

int main() {
    LinkedList list1, list2;

    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.insert(4);
    list2.insert(5);
    list2.insert(6);
    list1.intersect(list2, 2);
    cout << list1.findIntersection(list2) << endl;
    list1.print();
    list2.print();

    return 0;
}