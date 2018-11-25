/*
 * Minimum Vertices to Traverse Directed Graph
 * 
 * ex. input={{2,9},{3,3},{3,5},{3,7},{4,8},{5,8},{6,6},{7,4},{8,7},{9,3},{9,6}}, n=10
 * answer is 3
 * start from node 0, 1, 2
 *
 */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

void visit(unordered_map<int, set<int>> &g, set<int>& visited, set<int>& currVisited, set<int>& res, int start, int cur){

    currVisited.insert(cur);
    visited.insert(cur);

    for(int next:g[cur]){
        if(res.count(next) && next!=start){
            res.erase(next);
        }
        if(!currVisited.count(next)){
            visit(g, visited, currVisited, res, start, next);
        }
    }

}

int getMin(vector<vector<int>>& edges, int n){

    unordered_map<int, set<int>> g;

    for(auto e:edges){
        int a=e[0];
        int b=e[1];
        g[a].insert(b);
    }

    set<int> res;
    set<int> visited;

    for(int i=0;i<n;i++){
        if(!visited.count(i)){
            res.insert(i);
            set<int> currVisited; 
            visit(g, visited, currVisited, res, i, i);
        }
    }
    
    for(int n:res) 
        cout<<n<<" ";
    cout<<endl;

    int cnt=res.size();
    return cnt;

}

int main(){
    vector<vector<int>> edges{{2,9}, {3,3}, {3,5}, {3,7}, {4,8}, {6,6}, {7,4}, {8,7}, {9,3}, {9,6}};
    int nodes=10; //from 0 to 9
    cout<< getMin(edges, nodes)<<endl;

    vector<vector<int>> edges2{{0,0}, {1,2}, {2,0}, {2,3}, {3,1}};
    int nodes2=4;
    cout<< getMin(edges2, nodes2)<<endl;
    

}


