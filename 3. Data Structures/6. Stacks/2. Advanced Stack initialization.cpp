#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <initializer_list>
using namespace std;

#define n 100

// LIFO rocks, FIFO sucks
template<typename dataType>
class Stack {
private:
    vector<dataType> array;
public:
    Stack(initializer_list<dataType> values) : array(values){}

    void push(const dataType& value){
        array.push_back(value);
    }
    void pop(){
        if(!array.empty()){
            array.pop_back();
        }
    }
    const dataType& top()&{
        if(!array.empty()){
            return array.back();
        }
        else {
            cerr << "Stack is Empty" << endl;
            return -1;
        }
    }
    void clear(){
        array.clear();
    }
    bool empty()const{
        return array.empty();
    }
    int size(){
        return array.size();
    }
    void print(){
        cout << "Top -> ";
        for(auto i = array.rbegin(); i != array.rend(); i++){
            cout << *i << " ";
        }
        cout << "<- Bottom" << endl;
    }
    const dataType& operator[](size_t index)const{
        if(index < array.size()){
            return array[index];
        }
        else{
            cerr << "Index out of bound" << endl;
            return array.front();
        }
    }
};

int main(){
    Stack<string> stack = {"stacks","are","awesome"};
    for(int i = 0; i < stack.size(); i++){
        cout << stack[i] << endl;
    }
    return 0;
}