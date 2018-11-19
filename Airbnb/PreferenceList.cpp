/*
 *
 * ex. [[3, 5, 7, 9], [2, 3, 8], [5, 8]]
 * [2, 3, 5, 7, 8, 9]
 * If two number have same priority, break tie by person 1. 
 * 
 * https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=218938
 *
 */


#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
using namespace std;

void preferenceList(vector<vector<int>> &preferences){
    vector<int> res;
    map<int, vector<int>> g;
    map<int, int> degree;

    for(int i=0;i<preferences.size();i++){
        for(int j=1;j<preferences[i].size();j++){
            int a=preferences[i][j-1];
            int b=preferences[i][j];
            g[a].push_back(b);
            degree[b]++;
            if(degree.count(a)==0)
                degree[a]=0;
        }
    }

    queue<int> q;

    for(auto d:degree){
        int node=d.first;
        int val=d.second;
        if(val==0) 
            q.push(node);
    }
    
    while(!q.empty()){

        int num=q.size();
        set<int> tmp;
        
        //Many nodes with incoming degree 0 
        for(int i=0;i<num;i++){
            int cur=q.front();
            q.pop();
            tmp.insert(cur);

            for(int n:g[cur]){
                if(--degree[n]==0)
                    q.push(n);
            }
        }
    
        //Decide the order by scanning through original array 
        //O(n)
        for(int i=0;i<preferences.size();i++){
            for(int j=0;j<preferences[i].size();j++){
                if(tmp.count(preferences[i][j])){
                    int n=preferences[i][j];
                    res.push_back(n);
                    tmp.erase(n);
                }
            }
        }
    }

    for(int n:res)
        cout<<n<<endl;
}

int main(){
    vector<vector<int>> preferences{{3,5,7,9}, {2,3,8}, {5,8}};
    preferenceList(preferences);
}
