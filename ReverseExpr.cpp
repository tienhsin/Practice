#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class Expr{
public:
    string reverseExpr(string exp){
        
        reverse(exp.begin(), exp.end());

        for(int i=0;i<exp.size();i++){
            if(isNum(exp[i])){
                int start=i;
                int end=i+1;
                for( ; isNum(exp[end]) || exp[end]=='.' || (exp[end]=='-' && isExp(exp[end+1])) ; end++){i=end;}
                reverse(exp.begin()+start,exp.begin()+end);
            }
        }

        return exp;
    }

    bool isExp(char c){
        return c=='+' || c=='-' || c=='*' || c=='/';    
    }

    bool isNum(char c){
        return c-'0'>=0 && c-'0'<10;
    }
};

int main(){
    Expr ex;
    cout << ex.reverseExpr("1*2.4+-9.6-23.89") << endl;
    cout << ex.reverseExpr("2*3.5+15/-2.1") << endl;
}
