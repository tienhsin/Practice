#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


/* 
 * Time O(N*D)
 * Space O(1)
 */
class Solution1{

public:    

    vector<int> findAncestor(int D, vector<int> A){
        
        int n=A.size();
        vector<int> res(n, -1);
        
        //Find the Dth parent for each node
        for(int i=1;i<n;i++)
            res[i]=findParent(A, D, i);

        return res;
    }

    int findParent(vector<int> &A, int D, int cur){
        
        if(D==0 || cur==-1) return cur;
        return findParent(A, D-1, A[cur]);

    }

};

/*
 * Time O(N) 
 * Space O(N)
 */
class Solution2{
    public:
        vector<int> findAncestor(int D, vector<int> A){
           
            unordered_map<int, vector<int>> tree;
            for(int i=0;i<A.size();i++){
                tree[A[i]].push_back(i);
            }
            
            vector<int> res(A.size(), -1);
            vector<int> ancestors{0};
            dfs(res, tree, ancestors, D, 0);

            return res;
        }

        void dfs(vector<int>& res, unordered_map<int, vector<int>> &tree, vector<int>& ancestors, int D, int cur){
            
            int k=ancestors.size()-D-1;
            if(k>=0){
                res[cur]=ancestors[k];
            }else{
                res[cur]=-1;
            }
            
            for(int i=0;i<tree[cur].size();i++){
                ancestors.push_back(tree[cur][i]);
                dfs(res, tree, ancestors, D, tree[cur][i]);
                ancestors.pop_back();
            }

        }
};


int main(){
    
    Solution1 a;
    vector<int> in={-1, 0, 1, 2, 3};
    vector<int> in2={-1, 0, 1, 2, 3, 0, 5, 6, 7, 5, 9};
    vector<int> out=a.findAncestor(2, in);
    
    for(int o:out)
        cout<<o<<endl;

    cout<<endl;

    Solution2 b;
    vector<int> out2=b.findAncestor(3, in2);

    for(int i=0;i<out2.size();i++)
        cout<<i<<" "<<out2[i]<<endl;

}
