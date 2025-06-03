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

// Permutation

vector<vector<int>> answer;

void permutate(vector<int>&V, int idx){
    if(idx == V.size()){
        answer.push_back(V);
        return;
    }
    for(int i = idx; i < V.size(); i++){
        swap(V[i], V[idx]);
        permutate(V, idx+1);
        swap(V[i], V[idx]);
    }
    return;
}

int main(){
    vector<int> MyVect = {1,2,3};
    int indx = 0;

    permutate(MyVect, indx);

    for(auto rows : answer){
        for(auto cols : rows){
            cout << cols << " ";
        }
        cout << endl;
    }
    return 0;
}