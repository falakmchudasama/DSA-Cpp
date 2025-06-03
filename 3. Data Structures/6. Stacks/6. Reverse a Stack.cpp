#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

#define n 100

class Stack {
private:
    int* array;
    int Top;

public:
    Stack() {
        array = new int[n];
        Top = -1;
    }

    void push(int value) {
        if (Top >= n - 1) {
            cout << "StackOverflow" << endl;
        }
        Top++;
        array[Top] = value;
    }

    void pop() {
        Top--;
    }

    int top() {
        int result = array[Top];
        return result;
    }

    void clear() {
        Top = -1;
    }

    bool empty() {
        return (Top < 0);
    }

    void print() {
        for (int i = 0; i <= Top; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    int operator[](int index) const {
        if (index <= Top) {
            return array[index];
        } else {
            cerr << "Index > Top" << endl;
            return -1;
        }
    }
};

void insertAtBottom(Stack& stck, int e) {
    if (stck.empty()) {
        stck.push(e);
        return;
    }

    int topElement = stck.top();
    stck.pop();
    insertAtBottom(stck, e);
    stck.push(topElement);
}

void reverseStack(Stack& stck) {
    if (stck.empty()) {
        return;
    }
    int element = stck.top();
    stck.pop();
    reverseStack(stck);
    insertAtBottom(stck, element);
}

int main() {
    Stack stack;
    for(int i = 1; i < 10; i++){
        stack.push(i);
    }
    reverseStack(stack);
    stack.pop();
    stack.print();
    return 0;
}