#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixtoPre(string infix){
    reverse(infix.begin(), infix.end());
    stack<char> stck;
    string result;

    for(int i = 0; i < infix.length(); i++){
        char c = infix[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            result += c;
        }
        else if(c == ')'){
            stck.push(c);
        }
        else if(c == '('){
            while(!stck.empty() && stck.top() != ')'){
                result += stck.top();
                stck.pop();
            }
            if(!stck.empty()){
                stck.pop();
            }
        }
        else{
            while(!stck.empty() && precedence(stck.top()) >= precedence(c)){
                result += stck.top();
                stck.pop();
            }
            stck.push(c);
        }
    }
    while(!stck.empty()){
        result += stck.top();
        stck.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    string infix = "(a-b/c)*(a/k-l)";
    cout << infixtoPre(infix) << endl;
    return 0;
}