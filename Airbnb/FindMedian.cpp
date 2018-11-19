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
            else if(n!=m)
                next=min(next,n);
        }
        
        //cout<<"m:"<<m<<" cnt:"<<cnt<<endl;

        if(cnt==N-1){
            return next;
        }else if(cnt<N-1){
            lower=m+1;
        }else{
            upper=m-1;
        }
    }

    return 0;
}

int main(){
    vector<int> in{1,2,3,4,5,10,88,100,0,7,1110,6,7,6};
    
    int len=in.size();
    if(len%2==1){
        cout<<FindMedian(in, len/2)<<endl;
    }else{
        int a=FindMedian(in, len/2);
        int b=FindMedian(in, len/2-1);
        cout<<a<<endl;
        cout<<b<<endl;
        cout<< double(a+b)/2<<endl;
    }

}
