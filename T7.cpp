#include<iostream>
#include<vector>

using namespace std;

class myClass{
public:
    int imageMatching(vector<vector<int>> &m1, vector<vector<int>> &m2){
        int count=0;
        
        for(int i=0;i<m1.size();i++){
            for(int j=0;j<m1[0].size();j++){
                if(m1[i][j]==1){
                    count+=DFS(m1, m2, i, j);
                }
            }
        }

        return count;  
    }

    int DFS(vector<vector<int>> &m1, vector<vector<int>> &m2, int i, int j){
        
        if(i<0 || i>=m1.size() || j<0 || j>=m1[0].size()) return 1;
        if(m1[i][j]==0 && m2[i][j]==1) return 0;
        if(m1[i][j]==0) return 1;
        
        m1[i][j]=0;
        
        int count=m2[i][j];
        m2[i][j]=0;
        count &= DFS(m1, m2, i-1, j); 
        count &= DFS(m1, m2, i+1, j); 
        count &= DFS(m1, m2, i, j-1); 
        count &= DFS(m1, m2, i, j+1);

        return count;
    }

};


int main(){

    vector<vector<int>> m1{{1,0,1}, {0,1,0}, {1,0,0}};
    vector<vector<int>> m2{{1,0,1}, {0,1,0}, {1,0,0}};
    
    myClass A;
    
    cout<< A.imageMatching(m1,m2) << endl;
    
}
