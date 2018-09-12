#include<iostream>
#include<vector>
#include<string>

using namespace std;


class myClass{
public:
    vector<string> findMissingWords(string a, string b){
        vector<string> res;
        
        vector<string> wordA;
        string tmp;

        for(int i=0;i<a.size();i++){
            if(a[i]==' '){
                wordA.push_back(tmp);
                tmp.clear();
                continue;
            }
            tmp.push_back(a[i]);
        }
        
        wordA.push_back(tmp);
        tmp.clear();

        int k=0;
        for(int i=0;i<=b.size();i++){
            if(i==b.size() || b[i]==' '){
                while(k<wordA.size() && wordA[k]!=tmp) 
                    res.push_back(wordA[k++]);
                k++;
                tmp.clear();
                continue;
            }
            tmp.push_back(b[i]);
        }


        return res;
    }

};


int main(){
    myClass A;
    vector<string> A1=A.findMissingWords("I am using hackerrank to improve programming", "am using to programming");
    for(int i=0;i<A1.size();i++){
        cout<<A1[i]<<endl;
    }

}

