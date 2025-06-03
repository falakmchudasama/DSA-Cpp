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

bool balancedOrNot(string str){
    stack<char> stck;
    for(int i = 0; i < str.size(); i++){
        char c = str[i];
        if(c == '(' || c == '[' || c == '{'){
            stck.push(c);
        }
        else if(c == ')'){
            if(stck.top() == '('){
                stck.pop();
            }
        }
        else if(c == ']'){
            if(stck.top() == '['){
                stck.pop();
            }
        }
        else if(c == '}'){
            if(stck.top() == '{'){
                stck.pop();
            }
        }
    }
    return stck.empty();
}

int main(){
    string balanced = "{[()]}";
    string unbalanced = "{[()}]";

    cout << balancedOrNot(balanced) << endl;
    cout << balancedOrNot(unbalanced) << endl;
    return 0;
}