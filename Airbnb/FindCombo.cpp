/*
 * Find Case Combinations of a String
 * 
 * ex.
 * "ab" >>> "ab", "Ab", "aB", "AB"
 *
 */ 


#include<iostream>
#include<vector>

using namespace std;

void helper(vector<string>&, string&, string , int);
char toOppo(char);

void findCombo(string& s){
    vector<string> res;

    helper(res, s, "", 0);
    
    for(string r:res)
        cout<<r<<endl;
}

void helper(vector<string> &res, string &s, string tmp, int pos){
    if(pos==s.size()){
        res.push_back(tmp);
        return;
    }

    tmp.push_back(s[pos]);
    helper(res, s, tmp, pos+1);
    tmp.pop_back();
    tmp.push_back(toOppo(s[pos]));
    helper(res, s, tmp, pos+1);
    tmp.pop_back();

}

char toOppo(char c){
    if(c>='a' && c<='z')
        return c-'a'+'A';
    else
        return c-'A'+'a';
}

int main(){
    string s="Aa";
    findCombo(s);
}

