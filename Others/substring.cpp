#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class myClass{
public:
    void findSubstrings(string word){
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        unordered_set<char> consonants{'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
        unordered_set<string> visited;
        
        vector<string> valid;
        vector<string> invalid;

        for(int i=0;i<word.size()-1;i++){
            for(int j=i+2;j<=word.size();j++){
                
                string sub=word.substr(i, j-i);
                if(visited.count(sub)) continue;
                
                visited.insert(sub);
                int n=sub.size();
                if(vowels.count(sub[0]) && consonants.count(sub[n-1])){
                    valid.push_back(sub);
                }else{
                    invalid.push_back(sub);
                }
            }   
        }

        for(string s:valid){
            cout<<s<<" ";
        }
        cout<<endl;

        for(string s:invalid){
            cout<<s<<" ";
        }
        cout<<endl;

    }
};


int main(){
    myClass A;
    A.findSubstrings("abc");
    A.findSubstrings("aaaaccccc");
}

