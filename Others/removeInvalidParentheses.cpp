/*
 * The output is a valid result
 * 
 * ex.
 * ((()) => (()) 
 * 
 * ()))() => ()()
 *
 */


#include<iostream>
#include<vector>
using namespace std;


void removeInvalid(string in){
    
    int cnt=0;
    string s1;
    
    for(int i=0;i<in.size();i++){
        
        if(in[i]!=')' && in[i]!='('){
            s1.push_back(in[i]);
            continue;
        }

        if(in[i]=='('){
            s1.push_back(in[i]);
            cnt++;
        }else{
            if(cnt>0){;
                s1.push_back(in[i]);
                cnt--;
            }
        }
    }
    
    string res;
    cnt=0;
    for(int i=s1.size()-1;i>=0;i--){
        if(s1[i]!=')' && s1[i]!='('){
            res.push_back(s1[i]);
            continue;
        }
        if(s1[i]==')'){
            res.push_back(s1[i]);
            cnt++;
        }else{
            if(cnt>0){
                res.push_back(s1[i]);
                cnt--;
            }
        }
    }
    
    reverse(res.begin(), res.end());
    cout << res <<endl;
}

int main(){
    string in="(aaa))cd)()";
    removeInvalid(in);
}
