#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class myClass{
public:
    int longestChain(vector<string>& dict){
        sort(dict.begin(), dict.end(), [](string &a, string &b){
            return a.size()<b.size();
        });

        unordered_map<string, int> m;
        int max_len=0;

        for(string word:dict){
            
            if(m.count(word)) continue;

            m[word]=1;
            for(int i=0;i<word.size();i++){
                string next=removeCharAtI(word, i);
                if(m.count(next)){
                    m[word]=max(m[next]+1, m[word]); 
                }
            }
            max_len=max(max_len, m[word]);
        }
        
        return max_len;
    }

    string removeCharAtI(string word, int i){
        return word.substr(0, i)+word.substr(i+1);
    }

};

int main(){
    myClass A;
    vector<string> w1{"b","ba","bca","bdca","ebdca"};
    vector<string> w2{"b","ba","bca","bdca","ebdca","b"};
    vector<string> w3{"4","9","a","b","bca","ba","bde","bda","bdcae","bdca","abcde"};
    vector<string> w4{"abc", "bc", "c"};
    vector<string> w5{"a","b","ba","bca","bda","bdca"};
    
    cout << A.longestChain(w1) << endl;
    cout << A.longestChain(w2) << endl;
    cout << A.longestChain(w3) << endl;
    cout << A.longestChain(w4) << endl;
    cout << A.longestChain(w5) << endl;
    
}
