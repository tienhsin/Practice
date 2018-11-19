#include<fstream>
#include<iostream>
#include<nlohmann/json.hpp>
#include<map>
#include<set>
#include<string> 
#include<vector>

using namespace std;

int main(){
    
    ifstream in("people.json", ifstream::binary);
    nlohmann::json data;
    in>>data;
    
    map<string, map<string, int>> m;
    set<string> myset;

    for(nlohmann::json::iterator it=data.begin(); it!=data.end(); it++){
        string date=it.value()["date"];
        string country=it.value()["country"];
        m[date][country]++;
        myset.insert(country);
    }

    int total=myset.size();
    vector<string> res; 
        
    for(auto &i:m){
        if(i.second.size()==total){
            string date=i.first;
            res.push_back(date);
        }
    }
    
    nlohmann::json resJson(res);

    ofstream out("out.json");
    out << setw(4) << resJson << endl;

}
