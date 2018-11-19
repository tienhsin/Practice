#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<string> sortDate(vector<string> dates){
    sort(dates.begin(), dates.end(), [](string &a, string &b){
        
        int yearA=stoi(a.substr(7));
        int yearB=stoi(b.substr(7));
        if(yearA!=yearB) return yearA<yearB;
        
        unordered_map<string, int> m;
        m["Mar"]=3; m["Feb"]=2; m["Jan"]=1;
        
        int monthA=m[a.substr(3,3)];
        int monthB=m[b.substr(3,3)];

        if(monthA!=monthB) return monthA<monthB;

        int dateA=stoi(a.substr(0,2));
        int dateB=stoi(b.substr(0,2));

        return dateA<=dateB;

    });

    return dates;
}

int main(){
    vector<string> dates={"01 Mar 2017", "03 Feb 2017", "15 Jan 1998"};
    vector<string> res=sortDate(dates);
    for(string s:res)
        cout<<s<<endl;
}
