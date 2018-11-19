#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> scores{0,100,44,90,30,70};
    typedef pair<int,int> person;
    vector<person> ranks;

    for(int i=0;i<scores.size();i++){
        ranks.push_back({scores[i],i});
    }

    sort(ranks.begin(), ranks.end(), [](person a, person b){
        return a.first > b.first;    
    });

    for(auto a:ranks){
        cout<<a.first<<" "<< a.second<< endl;
    }
}
