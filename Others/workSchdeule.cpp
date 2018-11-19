#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<string>& res, string pattern, int dayHours, int workHours, int pos){
    
    while(pos<7 && pattern[pos]!='?') pos++;
    
    if(pos==7){
        if(workHours==0) res.push_back(pattern);
        return;
    }

    for(int i=0;i<=dayHours;i++){
        if(workHours-i<0) break;

        pattern[pos]='0'+i;
        dfs(res, pattern, dayHours, workHours-i, pos);
        pattern[pos]='?';
    }
}


vector<string> workSchdeule(string pattern, int dayHours, int workHours){
    
    vector<string> res;
    for(int i=0;i<pattern.size();i++){
        if(pattern[i]>='0' && pattern[i]<='9') 
            workHours-=pattern[i]-'0';
    }
    cout<<workHours<<endl;
    
    dfs(res, pattern, dayHours, workHours, 0);
    
    return res;
}

int main(){
    vector<string> s=workSchdeule("08?8??0", 8, 24);
    for(string ss:s){
        cout<<ss<<endl;
    }
}
