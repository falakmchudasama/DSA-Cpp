#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

#define n 1000000

// LIFO rocks, FIFO sucks
class Stack {
private:
    long long int* array;
    long long int Top;
    long long int largestElement = 0;
public:
    Stack(){
        array = new long long int[n];
        Top = -1;
    }
    void push(int value){
        if(Top > n){
            cout << "StackOverflow" << endl;
        }
        if (value >= largestElement){
            largestElement = value;
        }
        Top++;
        array[Top] = value;
    }
    void pop(){
        Top--;
    }
    long long int top(){
        long long int result = array[Top];
        return result;
    }
    void clear(){
        Top = -1;
    }
    bool empty(){
        if(Top < 0){
            return true;
        }
        return false;
    }
    void print(){
        for(long long int i = 0; i <= Top; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }
    long long int getMax(){
        return largestElement;
    }
};

int main(){
    return 0;
}