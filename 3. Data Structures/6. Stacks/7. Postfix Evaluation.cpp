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

#define n 100

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

int prefixEval(string str){
    Stack stck;
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            stck.push(str[i]-'0');
        }
        else if (str[i] == ' '){
            continue;
        }
        else {
            int op2 = stck.top();
            stck.pop();
            int op1 = stck.top();
            stck.pop();
            switch(str[i]){
                case '+':
                    stck.push(op1 + op2);
                    break;
                case '-':
                    stck.push(op1 - op2);
                    break;
                case '*':
                    stck.push(op1 * op2);
                    break;
                case '/':
                    stck.push(op1 / op2);
                    break;
                case '^':
                    stck.push(pow(op1, op2));
                    break;
            }
        }
    }
    return stck.top();
}

int main(){
    string str = "4 6 + 2 / 5 * 7 +";
    cout << prefixEval(str) << endl;
    return 0;
}