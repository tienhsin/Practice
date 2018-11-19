#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution{
    public:
        vector<int> storeHouse(vector<int> stores, vector<int> houses){

            sort(stores.begin(), stores.end());

            int n=houses.size();
            vector<int> res(n);

            for(int i=0;i<n;i++){
                res[i]=binarySearch(stores, houses[i]);
            }
            
            return res;
        }

        int binarySearch(vector<int> &stores, int house){
            int l=0, r=stores.size()-1;
        
            while(l<r){

                if(r-l==1){
                    return abs(stores[r]-house)<abs(stores[l]-house)?stores[r]:stores[l];
                }

                int mid=l+(r-l)/2;
                
                if(stores[mid]==house){
                    return stores[mid];
                }else if(stores[mid]>house){
                    r=mid;   
                }else{
                    l=mid;
                }

            }

            return stores[l];

        }

};

int main(){
    Solution a;
    vector<int> out=a.storeHouse({1,5,20,11,16,100}, {5,10,17,100,4000,4});
    for(int o:out)
        cout<<o<<endl;
}
