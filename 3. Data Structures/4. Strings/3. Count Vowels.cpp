#include <iostream>
#include <string>
using namespace std;

int CountVowels(string stringe) {
    int v = 0;
    for (int i = 0; i < stringe.length(); i++) {
        if (stringe[i] == 'a' || stringe[i] == 'e' || stringe[i] == 'i' || stringe[i] == 'o' || stringe[i] == 'u' || stringe[i] == 'A' || stringe[i] == 'E' || stringe[i] == 'I' || stringe[i] == 'O' || stringe[i] == 'U') {
            v++;
        }
    }
    return v;
}

int main(){
    string str = "AioE";
    int vowels = CountVowels(str);
    cout << vowels << endl;
    return 0;
}