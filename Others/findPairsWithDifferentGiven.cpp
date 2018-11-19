
#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*vector<vector<int>> findPairsWithGivenDifference( const vector<int>& arr, int k)
{
    // your code goes here
    vector<vector<int>> res;
    vector<int> arr_copy=arr;
    sort(arr_copy.begin(), arr_copy.end());
    
    for(int i=0;i<arr.size();i++){
        for(int j=arr_copy.size()-1;j>=0;j--){
            if(arr_copy[j]<arr[i]) continue;
            if(arr_copy[j]-arr[i]==k){
                vector<int> tmp;
                tmp.push_back(arr_copy[j]);
                tmp.push_back(arr[i]);
                res.push_back(tmp);
            }
        }
    }
    
    return res;
    
}*/

vector<vector<int>> findPairsWithGivenDifference(vector<int> arr, int k){
    map<int, int> m;
    vector<vector<int>> res;

    for(int i=0;i<arr.size();i++){
        m[arr[i]-k]=arr[i];
    }

    for(int i=0;i<arr.size();i++){
        int y=arr[i];
        if(m.count(y))
            res.push_back({m[y], y});
    }

    return res;

}

int main() {
    vector<int> arr{0, -1, -2, 2, 1};
    vector<vector<int>> res=findPairsWithGivenDifference( arr, 1);
    
    for(int i=0;i<res.size();i++){
        cout<<res[i][0] << " " << res[i][1] << endl;
    }
    
    return 0;
}

/*
 
 input:  arr = [0, -1, -2, 2, 1], k = 1
 output: [[1, 0], [0, -1], [-1, -2], [2, 1]]
 
 [1,0]
 
 */

/*
 abs (arr[0]-arr[4]) ==1
 
 for(int i=0;i<arr.size()-1;i++){
 for(int j=i+1;j<arr.size();j++){
 if(abs(arr[i]-arr[j])==k)
 res.push_back({arr[i], arr[j]});
 }
 }
 
 [0, -1], [0, 1], [-1, -2], [2, 1] ,
 
 arr_copy [-2, -1, 0, 1, 2]
 arr [0, -1, -2, 2, 1]
 i
 
 arr_copy[j] < arr[i]
 
 
 
 [-1,0], [-2,-1] [1, 2]
 
 if(arr[i]-arr_copy[j]==k)
 
 res.push_back({arr_copy[j], arr[i]});
 
 */
