/*
 *
 * input: ABAABC cooldown = 3
 * output: AB--A---ABC time = 11
 *
 *
 */


#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;


void taskScheduler(string &s, int cooldown){
    vector<char> res;
    unordered_map<char, int> m;

    int cur=0;
    for(char c:s){
        while(m.count(c) && cur-m[c]<=cooldown){
            res.push_back('*');
            cur++;
        }
        res.push_back(c);
        m[c]=cur;
        cur++;
    }
    
    for(char c: res)
        cout<<c;
    cout<<endl;
    cout<<cur<<endl;
}



void taskScheduler2(string &s, int cooldown){
    queue<pair<char, int>> q;
    unordered_set<char> working;
    int cur=0;


    for(char c:s){

        while(working.count(c)){
            char t = q.front().first;
            int start = q.front().second;
            q.pop();
            working.erase(t);
            if(t == c){
                cur = start + cooldown + 1; 
                break;
            }
        }
        while(!q.empty() && q.front().second < cur-cooldown )
            q.pop();

        q.push({c, cur});
        working.insert(c);
    }

}

/*
void taskScheduler2(string &s, int cooldown){
    unordered_map<char, int> freq;
    for(char c: s)
        freq[c]++;

    priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;

    for(auto f:freq){
        pq.push({f.first, f.second});
    }

    int cnt=0;
    vector<char> res;

    while(!pq.empty()){

        vector<pair<char, int>> tmp;

        for(int i=0;i<cooldown;i++){
            if(!pq.empty()){
                tmp.push_back(pq.top());
                pq.pop();
            }
            cnt++;
        }

        for(int i=0;i<tmp.size();i++){
            if(--tmp[i].second>0)
                pq.push(tmp[i]);
            res.push_back(tmp[i].first);
        }
    }

    for(char c:res)
        cout<<c;
    cout<<endl;
    cout<<cnt<<endl;

}
*/

int main(){
    string in="ABAABCDEFGHIJKLMNOP";
    taskScheduler(in, 3);
    //taskScheduler2(in, 3);
}


