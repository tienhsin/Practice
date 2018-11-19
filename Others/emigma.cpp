#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class MyClass{
    public:
        int calculateTotalRotor(int rotorCount, int minRotorValue, int maxRotorValue){

            vector<vector<int>> res;
            vector<int> tmp;

            for(int i=minRotorValue;i<=maxRotorValue;i++){
                int firstRotor=i;
                tmp.push_back(firstRotor);
                vector<int> coPrime=coPrimeWithFirstRotor(firstRotor, minRotorValue, maxRotorValue);
                backtracking(res, tmp, rotorCount-1, coPrime);
                tmp.pop_back();
            }

            for(auto r:res){
                for(auto k:r)
                    cout<<k<<" ";
                cout<<endl;
            }

            int count=res.size();
            return count;

        }

        vector<int> coPrimeWithFirstRotor(int firstRotor, int minRotorValue, int maxRotorValue){
            vector<int> res;
            for(int i=minRotorValue;i<=maxRotorValue;i++){
                if(gcd(firstRotor, i)==1)
                    res.push_back(i);
            }
            return res;
        }

        void backtracking(vector<vector<int>>& res, vector<int>& tmp, int rotorCount, vector<int>& coPrime){
            if(rotorCount==0){
                res.push_back(tmp);
                return;
            }

            for(int j=0;j<coPrime.size();j++){
                tmp.push_back(coPrime[j]);
                backtracking(res, tmp,rotorCount-1, coPrime);
                tmp.pop_back();
            }

        }
        
        int gcd(int a, int b){
            return b==0?a:gcd(b, a%b);
        }


};

int main(){
    int rotorCount=3;
    int minRotorValue=2;
    int maxRotorValue=10;

    MyClass A;
    int count=A.calculateTotalRotor( rotorCount, minRotorValue, maxRotorValue );

    cout<< count << endl;

    return 0;

}
