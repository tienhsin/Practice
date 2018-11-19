#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class myClass{
public:
    vector<int> findClosest(string s, int n, vector<int> &in){
        vector<int> res(n, -1);
        unordered_map<char, vector<int>> m;

        for(int i=0;i<s.size();i++){
            m[s[i]].push_back(i);
        }

        for(int k=0;k<res.size();k++){

            char c=s[in[k]];
            int id=in[k];
            
            //alphabet appears only once the in string 
            if(m[c].size()==1) continue;

            for(int j=0;j<m[c].size();j++){
                if(id==m[c][j]){
                    res[k]=findClosestNeighbor(m[c],id,j);
                    break;
                }    
            }
        }

        return res;
    }

   int findClosestNeighbor(vector<int> v, int id, int j){
       
       int ans=-1;
       
       if(j==0){
           ans=v[j+1];
       }else if(j==v.size()-1){
           ans=v[j-1];
       }else{
           if(abs(id-v[j+1])<abs(id-v[j-1]))
               ans=j+1;
           else
               ans=j-1;
       }

       return ans;
   }
};

int main(){
    myClass A;
    string s="aaaaaaaaaaaaa";
    vector<int> in{4,1,6,8};
    int n=in.size();
    vector<int> res=A.findClosest(s, n, in);

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    
}
