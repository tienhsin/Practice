/*
 * Input: A = [x1, x2, ..., xn]
 * 
 * Sum T = Round(x1+x2+... +xn) ; 178.93E => 179
 * Output: B = [y1, y2, ...., yn]
 * 
 * Constraint #1: y1+y2+...+yn = T
 * Constraint #2: minimize sum(abs(diff(xi - yi)))
 *
 *
 * A = [1.2, 2.3, 3.4]
 * Round(1.2 + 2.3 + 3.4) = 6.9 => 7 
 *
 * 1 + 2 + 3 => 6
 * 0.2 + 0.3 + 0.4 = 1.0
 *
 * 1 + 3 + 3 => 7
 * 0.2 + 0.7 + 0.4 = 1.3
 *
 * 1 + 2 + 4 => 7
 * 0.2 + 0.3 + 0.6 = 1.1 
 *
 * 所以[1,2,4]比[1,3,3]要好
 *
 */

#include<iostream>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

void roundPrice(vector<double> &A){
    
    int len=A.size();
    vector<int> res(len);
    vector<int> floorA(len); //rounded items of A

    double sum=0.0;
    for(double a:A) sum+=a;
    int target=round(sum);

    //cout<<"target: "<<target<<endl;
    
    int sumFloor=0;
    for(int i=0;i<len;i++){
        floorA[i]=floor(A[i]);
        sumFloor+=floorA[i];
    }

    //cout<<"total: "<<sumFloor<<endl;

    map<double, int> AandFloor; //diff between A and its floor value
    for(int i=0;i<len;i++){
        AandFloor[A[i]-floorA[i]]=i;
    }
    
    int diff=target-sumFloor;
    int _diff=len-diff;
    for( auto a:AandFloor ){
        int i=a.second;

        if(_diff>0){
            res[i]=floorA[i];    
        }else{
            res[i]=ceil(A[i]);
        }
        _diff--;
    }

    for(int n:res)
        cout<<n<<" ";
    cout<<endl;
}

int main(){
    vector<double> A{1.2, 2.3, 3.4}, B{1.2, 2.5, 3.6, 4.0};
    roundPrice(B);
}
