
#include<iostream>
#include<vector>
#include<cmath>
#include<map>
using namespace std;



void roundPrice(vector<double> &A){

    int len=A.size();
    
    double sum=0.0;
    for(double n:A) sum+=n;
    int target=round(sum);

    vector<int> floorA(len,0);
    vector<pair<double, int>> diffMap(len);

    int sumf=0;
    for(int i=0;i<A.size();i++){
        floorA[i]=floor(A[i]);
        sumf+=floorA[i];
        diffMap[i]={A[i]-floorA[i], i};
    }

    int diff = target-sumf;
    //floor(A[i]) => cail(A[i])
    
    sort(diffMap.begin(), diffMap.end(), [](pair<double, int> &a, pair<double, int> &b){
        return a.first>b.first;
    });
    
    vector<int> res(len);
    for(auto item:diffMap){
        int i=item.second;
        if(diff>0){
            res[i]=ceil(A[i]);
            diff--;
        }else{
            res[i]=floor(A[i]);
        }
    }

    for(int n:res)
        cout<<n<<" ";
    cout<<endl;
}


int main(){
    vector<double> A{1.2, 2.3, 3.4}, B{1.2, 2.5, 3.6, 4.0};
    roundPrice(B);
}
