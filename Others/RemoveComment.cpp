#include<iostream>
#include<string>
using namespace std;

class Remover{
public:
    string removeComments(string s){
        string out;
        int n=s.size();

        for(int i=0;i<n;i++){

            if(i!=n-1 && s[i]=='/' && s[i+1]=='/'){
                for(int j=i+2;j<n;j++){
                    if(s[j]=='\n'){
                        i=j+1;
                        break;
                    } 
                }

            }else if(i!=n-1 && s[i]=='/' && s[i+1]=='*'){
                for(int j=i+2;j<n-1;j++){
                    if(s[j]=='*' && s[j+1]=='/'){
                        i=j+2;
                        break;
                    }
                }
            }

            out.push_back(s[i]);
        }

        return out;
    } 

};

int main(){
    Remover r; 
    cout << r.removeComments("start /*1*/ \n // 2 \n int main(){ \n /*3 \n abc; \n }") << endl;

}
