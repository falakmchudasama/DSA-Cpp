#include <iostream>
#include <vector>
using namespace std;

void function(vector<int> Vector){

    cout<<"{";
    for (int i = 0; i < Vector.size(); i++){
        if (i == Vector.size()-1){
            cout<<Vector[i];
        }
        else {
            cout<<Vector[i]<<",";
        }
    }
    cout<<"}"<<endl;
}

int main(){
    vector<int> Vector = {9,5,6,3,7,5};
    function(Vector);
    return 0;
}