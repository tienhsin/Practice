/*
 *  Add parathesis to begin and end to make parathesis string valid.  
 *  )(()( => ()(()()) 
 *
 */


#include<iostream>
using namespace std;

void toValid(string& in){
    
    string res;
    
    int left=0;
    int cnt=0;
    for(int i=0;i<in.size();i++){
        if(in[i]=='(')
            cnt++;
        else{
            if(cnt==0){
                left++;
            }else{
                cnt--;
            }
        }
    }

    int right=0;
    cnt=0;
    for(int i=in.size()-1;i>=0;i--){
        if(in[i]==')'){
            cnt++;
        }else{
            if(cnt==0){
                right++;
            }else{
                cnt--;
            }
        }
    }

    while(left>0){
        res.push_back('(');
        left--;
    }
    
    res+=in;

    while(right>0){
        res.push_back(')');
        right--;
    }


    cout<<res<<endl;
}

int main(){
    string s=")(()(";
    toValid(s);

    string s1="()(";
    toValid(s1);
}

