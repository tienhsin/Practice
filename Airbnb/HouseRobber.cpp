/*
 * Given a set of numbers in an array which represent number of consecutive days of AirBnB reservation requested, 
 * as a host, pick the sequence which maximizes the number of days of occupancy, 
 * at the same time, leaving at least 1 day gap in between bookings for cleaning.
 *
 * ex.
 * [5, 1, 1, 5] => 10(i=0, i=3)
 *
 */ 

#include<iostream>
#include<vector>
using namespace std;


int maxSumWithGap(vector<int>& in){
    
    int n=in.size();
    
    if(in.size()<2)
        return in.empty()?0:in[1];

    vector<int> dp(n,0);
    dp[0]=in[0];
    dp[1]=max(dp[0],in[1]);

    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1], dp[i-2]+in[i]);
    }

    return dp[n-1];

}

int main(){
    vector<int> in{4, 10, 3, 1, 5}; //in{5,1,1,5};
    cout<<maxSumWithGap(in)<<endl;
}

