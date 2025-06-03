#include <iostream>
#include <vector>
using namespace std;

void function(vector<char> v1, vector<char> v2){
    vector<char> common = {};
    vector<char> result = {};
    if (v1.size() >= v2.size()){
        for (int i = 0; i < v1.size(); i++){
            for (int j = 0; j < v2.size(); j++){
                if (v2[j] == v1[i]){
                    common.push_back(v2[j]);
                }
            }
        }
    }

    else if (v1.size() <= v2.size()){
        for (int i = 0; i < v2.size(); i++){
            for (int j = 0; j < v1.size(); j++){
                if (v1[j] == v2[i]){
                    common.push_back(v1[j]);
                }
            }
        }
    }
    
    if (result.size() == 0){
        cout<<"The two vectors have no elements common :("<<endl;
    }
    else{
        cout<<"The Common Elements between the two vectors are: {";
        for (int i = 0; i < result.size(); i++){
            if (i == result.size()-1){
                cout<<result[i];
            }
            else {
                cout<<result[i]<<",";
            }
        }
        cout<<"}"<<endl;
    }
}

int main(){
    cout<<endl;
    vector<char> vector1 = {'b','q','p','q','x','a','h'};
    vector<char> vector2 = {'p','q'};
    function(vector1, vector2);
    return 0;
}