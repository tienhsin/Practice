
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class GuessNum{
private:
    string ans;

public:
    
    GuessNum(string s){
        ans=s;
    }

    int sendAndReceive(string s){
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(ans[i]==s[i])
                cnt++;
        }
        return cnt;
    }

};

void guess(string goal){
    GuessNum g(goal);

    int base=g.sendAndReceive("1111");
    string res="1111";
    int nums=1;

    for(int i=0;i<4;i++){
        int j=2;
        int cnt=0;
        for(;j<6;j++){
            
            nums++;
            res[i]=j+'0';
            cnt=g.sendAndReceive(res);
            
            if(cnt==4) break;

            if(cnt>base){
                base++;
                break;
            }else if(cnt<base){
                res[i]='1';
                break;
            }
        }
        if(cnt==4) break;
        if(j==6){
            res[i]='6';
            base++;
        }
    }

    cout<<res<<endl;
    cout<<nums<<endl;

}

int main(){
    guess("2211");
    guess("6666");
    guess("1234");
}
