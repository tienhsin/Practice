/*
 * To find the min cost between 0 and 9.
 * 
 * ex.
 * wizard[0] list: 1, 4, 5 wizard[4] list: 9 wizard 0 to 9 min distance is (0-4)^2+(4-9)^2=41 
 * (wizard[0]->wizard[4]->wizard[9])
 *
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Wizard{
    int i;
    int dis;
    Wizard(int i, int dis):i(i), dis(dis){}
};

void shortestPath(vector<vector<int>>& wizard){

    int n=wizard.size();
    vector<Wizard*> w(n);
    for(int i=1;i<n;i++){
        w[i]=new Wizard(i, INT_MAX);
    }
    w[0]=new Wizard(0, 0);

    queue<Wizard*> q;
    q.push(w[0]);

    while(!q.empty()){
        Wizard* cur=q.front();
        q.pop();
        for(int j:wizard[cur->i]){
            int newDist = cur->dis + (cur->i-j)*(cur->i-j);
            if(newDist<w[j]->dis){
                w[j]->dis=newDist;
                q.push(w[j]);
            }
        }
    }

    cout<<w[n-1]->i<<" "<<w[n-1]->dis<<endl;
    
}

int main(){
    vector<vector<int>> wizard(10);
    wizard[0]={1,2,4};
    wizard[4]={9};
    wizard[2]={9};

    shortestPath(wizard);
    
}
