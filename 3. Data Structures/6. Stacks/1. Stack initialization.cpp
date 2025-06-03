#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

#define n 100

// LIFO rocks, FIFO sucks
class Stack {
private:
    int* array;
    int Top;
public:
    Stack(){
        array = new int[n];
        Top = -1;
    }
    void push(int value){
        if(Top > n){
            cout << "StackOverflow" << endl;
        }
        Top++;
        array[Top] = value;
    }
    void pop(){
        Top--;
    }
    int top(){
        int result = array[Top];
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
        for(int i = 0; i <= Top; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }
    int operator[](int index)const{
        if(index <= Top){
            return array[index];
        }
        else{
            cerr << "Index > Top" << endl;
            return -1;
        }
    }
};

int main(){
    Stack stck;
    for(int i = 0; i <= 10; i++){
        stck.push(i);
    }
    for(int j = 0; j <= stck.top(); j++){
        cout << stck[j] << endl;
    }
    return 0;
}