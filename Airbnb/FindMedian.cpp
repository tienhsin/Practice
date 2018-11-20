/*
 * Find Median in Large File of Integers
 *
 */

#include<iostream>
#include<vector>

using namespace std;

int FindMedian(vector<int>& in, int N){
    long upper=INT_MAX, lower=INT_MIN;
    
    while(upper>=lower){
        int m=lower+(upper-lower)/2;
        int cnt=0; //number of elements smaller or equal to m 
        int next=INT_MAX;

        for(int n:in){
            if(m>n) cnt++;
            else
                next=min(next,n);
        }
        
        //cout<<"m:"<<m<<" cnt:"<<cnt<<endl;
        //cout<<"next:"<<next<<endl;

        if(cnt==N-1){
            return next;
        }else if(cnt<N-1){
            lower=m+1;
        }else{
            upper=m-1;
        }
    }

    return lower;
}

int main(){
    vector<int> in{1,2,3,4,5}; 
    int len=in.size();
    if(len%2==1){
        cout<<FindMedian(in, len/2+1)<<endl;
    }else{
        int a=FindMedian(in, len/2+1);
        int b=FindMedian(in, len/2);
        cout<<a<<endl;
        cout<<b<<endl;
        cout<< double(a+b)/2<<endl;
    }

    sort(in.begin(), in.end());
    for(int n:in)
        cout<<n<<" ";
}
