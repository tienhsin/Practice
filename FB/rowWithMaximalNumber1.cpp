/*
 *
 *  [0, 0, 0, 1, 1]
 *  [0, 1, 1, 1, 1]
 *  [0, 0, 1, 1, 1]
 *  
 *  return 1
 *
 *  https://www.geeksforgeeks.org/find-the-row-with-maximum-number-1s/
 */

#include<iostream>
#include<vector>
using namespace std;

/*
//O(mn)
int rowWithMax1s( vector<vector<int>> &in){ 
    
    
    for(int i=0;i<in[0].size();i++){
        for(int j=0;j<in.size();j++){
            if(in[j][i]==1){
                return j;
            }
        }
    }

    return -1;

}
*/

//O(m+n)
int first(vector<int> &v){
    int l=0, r=v.size()-1;
    
    while(l<r){
        int m=l+(r-l)/2;
        if(v[m]==0){
            l=m+1;
        }else{
            r=m;
        }   
    }
    
    if(l==v.size()-1 && v[l]==0) return -1;
    else return l;

}

int rowWithMax1s(vector<vector<int>> &in){

    int max_row_index = -1;
    int cur=-1;

    for(int i=0;i<in.size();i++){
        if(cur==-1){
            cur=first(in[i]);
            max_row_index=i;
        }else{
            while(cur>=0 && in[i][cur]==1){
                cur--;
                max_row_index=i;
            }
        }
    }

    return max_row_index;

}


int main(){
    vector<vector<int>> in{{0,0,0,0,0},{0,0,1,1,1},{0,0,0,1,1}};
    cout << rowWithMax1s(in) << endl;
}
