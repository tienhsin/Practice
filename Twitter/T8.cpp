/*
 * No pairs allowed
 */


#include<iostream>
#include<vector>
#include<string>

using namespace std;

class myClass{
public:
    vector<int> minimalOperation(vector<string> input){
        
        vector<int> res(input.size(),0);

        for(int i=0;i<input.size();i++){
            string cur=input[i];
            for(int j=0;j<cur.size()-1;j++){
                if(cur[j] == cur[j+1]){
                    res[i]++;
                    j++;
                }
            }
        }

        return res;
    }
};

int main(){
    myClass A;
    vector<string> input={"abccaa", "aabbbb", "abb","abab", "abaaaba"};
    vector<int> res=A.minimalOperation(input);
    for(int n:res) cout<<n<<endl;
    
}
