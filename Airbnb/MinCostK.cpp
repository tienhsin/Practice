#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<unordered_set>
#include<map>
using namespace std;


struct flight{
    string from;
    string to;
    int cost;
    flight(string from, string to, int cost):from(from), to(to), cost(cost){}
};

int minCost(vector<flight>&v, string from, string to, int k){
    map<string,map<string,int>> g;
    
    for(auto f:v){
        string a=f.from;
        string b=f.to;
        int c=f.cost;
        g[a][b]=c;
    }
    
    queue<string> q;
    q.push(from);

    map<string, int> costs;
    costs[from]=0;
    
    map<string, string> parent;
    parent[from]=from;

    while(!q.empty() && k>0){
        int len=q.size();
        k--;
        for(int i=0;i<len;i++){
            string cur=q.front();
            q.pop();
            int base=costs[cur];

            for(auto next:g[cur]){
                string name=next.first;
                int c=next.second;
                if(!costs.count(name) || costs[name]>c+base){
                    costs[name]=c+base;
                    q.push(name);
                    parent[name]=cur;
                }
            }
        }
    }

    string p=to;
    cout<<to<<" ";
    while(p!=from){
        p=parent[p];
        cout<<p<<" ";
    }
    cout<<endl;

    if(!costs.count(to))
        return -1;
    return costs[to];


}

int main(){
    vector<flight> v;
    v.push_back(flight("A", "B", 200));
    v.push_back(flight("B", "C", 200));
    v.push_back(flight("A", "C", 500));
    v.push_back(flight("A", "D", 1));
    v.push_back(flight("D", "E", 1));
    v.push_back(flight("E", "H", 1));
    v.push_back(flight("H", "C", 1));
    
    cout << minCost(v, "A", "C", 2) << endl;
    cout << minCost(v, "A", "C", 5) << endl;

}

