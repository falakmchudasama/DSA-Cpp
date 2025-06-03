#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

#define n 1000

// FIFO rocks, LIFO sucks
class Queue {
private:
    int* array;
    int front;
    int back;
public:
    Queue(){
        array = new int[n];
        front = -1;
        back = -1;
    }
    void enque(int value){
        if(back == n-1){
            cout << "Queue overflow" << endl;
            return;
        }
        back++;
        array[back] = value;

        if(front == -1){
            front++;
        }
    }
    void deque(){
        if(front > back || front == -1){
            cout << "Queue is Empty" << endl;
            return;
        }
        front++;
    }
    int peek(){
        if(front > back || front == -1){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int result = array[front];
        return result;
    }
    void clear(){
        front = -1;
        back = -1;
    }
    bool empty(){
        if(front < 0 || front > back){
            return true;
        }
        return false;
    }
    void print(){
        for(int i = front; i <= back; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Queue Q;
    for(int i = 0; i <= 100; i++){
        Q.enque(i);
    }
    Q.deque();
    Q.enque(101);
    Q.print();
    cout << Q.peek() << endl;
    Q.clear();
    cout << Q.empty() << endl;
    return 0;
}