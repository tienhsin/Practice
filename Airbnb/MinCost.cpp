/*
 * Input are start city, end city and an array of {depart city, dest city, cost};
 * Find the shortest path from start city to end city.
 *
 * ex.
 * start=A, end=B
 * A->B = 100
 * B->C = 100
 * A->C = 300
 * 
 * total = 200
 * path = [A, B, C]
 */

#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
using namespace std;

struct edge{
    string start;
    string end;
    int cost;
    edge(string s, string e, int c): start(s), end(e), cost(c){}
};

void traversal(vector<edge>& in, string start, string end){
    
    unordered_set<string> visited; 
    unordered_map<string, int> reachable; 
    unordered_map<string, string> parent;
    
    reachable[start]=0;
    string cur=start;

    while(cur!=end){

        visited.insert(cur); 
        int base=reachable[cur];

        for(auto e:in){
            string a=e.start;
            string b=e.end;
            int cost=e.cost;

            if(a==cur && visited.count(b)==0){
                if(reachable.count(b)==0 || base+cost<reachable[b]){
                    reachable[b]=base+cost;
                    parent[b]=a;
                }
            }
        }

        //Decide which node to visit next
        int min_cost=INT_MAX;
        string next;
        for(auto k:reachable){
            string node=k.first;
            int cost=k.second;
            if(visited.count(node)==0){
                if(cost<min_cost){
                    next=node;
                    min_cost=cost;
                }  
            }
        }

        cur=next;
    
    }

    string path=end;
    cur=end;
    while(cur!=start){
        cur=parent[cur];
        path+="<-"+cur;
    }
    
    cout<<reachable[end]<<endl;
    cout<<path<<endl;

}

int main(){
    string start="A";
    string end="C";
    edge a("A","B",100), b("A","C",100), c("B","C",100), d("B","D",50), e("D","E",20);
    vector<edge> in{a,b,c,d,e};
    traversal(in, start, end);
}
