/*
 * https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=278915
 *
 * ex. 
 * me["A", "B", "C", "D"]
 * a["A","B","E","F"]
 * b["A","B","C","E"]
 * c["B","E","F","G"]
 *
 * res = ["b","a"]
 * 
 */ 

#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>

using namespace std;

void TravelBuddy(set<string> &myList, map<string, set<string>> &buddyList){

    int n=myList.size();
    map<int, vector<string>> match; //Bob, me => 3 cities in same => map[3] = {Bob}

    for(auto buddy:buddyList){
        string name=buddy.first;
        set<string> listB=buddy.second;
        int com=0;
        
        for(string c:myList){
            if(listB.count(c)){
                com++;
            }
        }

        if(com>=(n+1)/2){ //larger than 50%
            match[com].push_back(name);
        }
    }

    vector<string> res;
    for(auto m:match){
        res.insert(res.end(), m.second.begin(), m.second.end());
    }
    
    reverse(res.begin(), res.end());
    for(string n:res)
        cout<<n<<" ";
    cout<<endl;
}


int main(){
    set<string> me{"A", "B", "C", "D", "LL"};
    map<string,set<string>> buddyList;
    buddyList["Amy"]={"A", "B", "F", "E", "LL"};
    buddyList["Bob"]={"A", "B", "H", "E", "MM"};
    buddyList["Can"]={"A", "G", "H", "E"};
    
    TravelBuddy(me, buddyList);
}
