#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

string RemoveDuplicates(string stringe) {
    set<char> MySet;
    string result;
    for (int i = 0; i < stringe.length(); i++) {
        MySet.insert(stringe[i]);
    }
    for (char c : MySet) {
        result += c;
    }
    return result;
}

int main(){
    string str = "HHeelloo";
    cout << RemoveDuplicates(str) << endl;
    return 0;
}