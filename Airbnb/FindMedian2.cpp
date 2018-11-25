

double search(vector<int>&in, int k){

    long left=INT_MAX;
    long right=INT_MIN;

    while(left<=right){
        int guess=left+(right-left)/2;
        int cnt=0;
        int ans=INT_MAX;

        for(int n:in){
            if(n<guess){
                cnt++;
            }else{
                ans=min(ans,n);
            }
        }

        if(cnt==k-1){
            return ans;
        }else if(cnt>k-1){
            right=guess-1;
        }else{
            left=guess+1;
        }
    }

    return left;

}

double FindMedian(vector<int>&in){
    
    int len=in.size();
    if(in%2==0){
        return double(search(in, len/2)+ search(in, len/2+1))/2;
    }else{
        return search(in, len/2); //arr, kth smallest element in arr 
    }

}
