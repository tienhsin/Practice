#include<iostream>
#include<vector>
#include<utility>
#include<unordered_map>
using namespace std;

int maxEdges(vector<int>& from, vector<int>& to){

    unordered_map<int, unordered_map<int,int>> m;
    int count=0, res=0;
    
    for(int i=0;i<from.size();i++){
        
        m[from[i]][to[i]]++;
        
        if(m[from[i]][to[i]] >= count){
            count=m[from[i]][to[i]];
            res=max(res, from[i]*to[i]);
        }
    }

    return res;
}

int main(){
    vector<int> from={1,1,2,2,2};
    vector<int> to={2,2,3,3,4};

    cout << maxEdges(from, to) << endl;

}


