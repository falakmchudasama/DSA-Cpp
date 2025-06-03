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
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void print() {
        if (head != nullptr) {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

    void reverse() {
        if (head != nullptr && head->next != nullptr) {
            Node* temp = head;
            Node* Current = temp;
            Node* Previous = nullptr;
            Node* Next = nullptr;
            while (Current != nullptr) {
                Next = Current->next;
                Current->next = Previous;
                Previous = Current;
                Current = Next;
            }
            head = Previous;
        }
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            count++;
        }
        return count;
    }

    LinkedList mergeList(LinkedList& list2) {
        LinkedList result;
        Node* temp1 = head;
        Node* temp2 = list2.head;

        while (temp1 != nullptr || temp2 != nullptr) {
            if (temp1 == nullptr) {
                result.insert(temp2->data);
                temp2 = temp2->next;
            } else if (temp2 == nullptr) {
                result.insert(temp1->data);
                temp1 = temp1->next;
            } else {
                if (temp1->data <= temp2->data) {
                    result.insert(temp1->data);
                    temp1 = temp1->next;
                } else {
                    result.insert(temp2->data);
                    temp2 = temp2->next;
                }
            }
        }
        return result;
    }

    LinkedList divideSort(Node* start) {
        if (start == nullptr || start->next == nullptr) {
            LinkedList result;
            if (start != nullptr) {
                result.insert(start->data);
            }
            return result;
        }
        Node* hare = start;
        Node* tortoise = start;
        while (hare != nullptr && hare->next != nullptr) {
            hare = hare->next->next;
            tortoise = tortoise->next;
        }
        Node* secondHalf = tortoise->next;
        tortoise->next = nullptr;
        LinkedList left = divideSort(start);
        LinkedList right = divideSort(secondHalf);

        return left.mergeList(right);
    }
    void sort() {
        head = divideSort(head).head;
    }
};

int main() {
    LinkedList unSorted1, unSorted2, Sorted1, Sorted2, Merged;

    // Unsorted list1
    unSorted1.insert(1);
    unSorted1.insert(9);
    unSorted1.insert(4);
    unSorted1.insert(10);
    unSorted1.insert(2);
    unSorted1.insert(15);

    // Unsorted list2
    unSorted2.insert(6);
    unSorted2.insert(3);
    unSorted2.insert(5);
    unSorted2.insert(12);
    unSorted2.insert(7);

    // Sorted list1
    Sorted1.sort();
    Sorted2.sort();

    // Merge 'em
    Merged = Sorted1.mergeList(Sorted2);
    Merged.print();

    return 0;
}
