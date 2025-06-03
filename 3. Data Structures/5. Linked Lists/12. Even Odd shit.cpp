#include <iostream>
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
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insert(int value) {
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

    void rearrangeEvenOdd() {
        if (head == NULL || head->next == NULL) {
            return; // No or only one node, nothing to rearrange
        }

        Node* oddHead = head;
        Node* evenHead = head->next;
        Node* oddTail = head;
        Node* evenTail = head->next;

        Node* current = evenHead->next;
        bool isOdd = true;

        while (current != NULL) {
            if (isOdd) {
                oddTail->next = current;
                oddTail = current;
            } else {
                evenTail->next = current;
                evenTail = current;
            }

            current = current->next;
            isOdd = !isOdd;
        }

        oddTail->next = evenHead;
        evenTail->next = NULL;
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

    cout << "Original List: ";
    list.print();

    list.rearrangeEvenOdd();

    cout << "Rearranged List: ";
    list.print();

    return 0;
}