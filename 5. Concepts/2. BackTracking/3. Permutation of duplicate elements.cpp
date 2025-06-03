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

// Permutation of duplicate elements

void helper(vector<int>V, vector<vector<int>>& answer, int idx){
    if(idx == V.size()){
        answer.push_back(V);
        return;
    }
    for(int i = idx; i < V.size(); i++){
        if(i != idx && V[i] == V[idx]){
            continue;
        }
        swap(V[i],V[idx]);
        helper(V, answer, idx+1);
        swap(V[i],V[idx]);
    }
}

vector<vector<int>> permutate(vector<int>&V, int idx){
    sort(V.begin(), V.end());
    vector<vector<int>> answer;
    helper(V, answer, 0);
    return answer;
}

int main(){
    vector<int> MyVect = {1,2,2};
    int indx = 0;

    vector<vector<int>> result = permutate(MyVect, indx);

    for(auto rows : result){
        for(auto cols : rows){
            cout << cols << " ";
        }
        cout << endl;
    }
    return 0;
}