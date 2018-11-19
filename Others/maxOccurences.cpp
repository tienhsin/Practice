#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int getmaxOccurrences(string s, int minLength, int maxLength, int maxUniqie){
    
    int res=0;
    unordered_map<string,int> freq;
    unordered_set<char> char_set;

    for(int i=0, j=0;i<s.size();i++){
        
        if(i-j>=minLength) char_set.erase(s[j++]);
        char_set.insert(s[i]);

        // is valid
        if(i-j==minLength-1 && char_set.size()<=maxUniqie){
            string tmp=s.substr(j, minLength);
            freq[tmp]++;
            res=max(res, freq[tmp]);
        }

    }


    return res;
}
    

int main(){
    string s="aaaabe";
    int minLength=2;
    int maxLength=5;
    int maxUniqie=3;

    cout<< getmaxOccurrences(s, minLength, maxLength, maxUniqie) << endl;
}
