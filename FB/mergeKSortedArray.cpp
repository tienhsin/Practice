/*
 * int[][] A = new[5][];
 *
 * A[0] = { 1, 5, 8, 9 };
 * A[1] = { 2, 3, 7, 10 };
 * A[2] = { 4, 6, 11, 15 };
 * A[3] = { 9, 14, 16, 19 };
 * A[4] = { 2, 4, 6, 9  };
 *
 * output
 * [1, 2, 2, 3, 4, 4, 5, 6, 6, 7, 8, 9, 9, 9, 10, 11, 14, 15, 16, 19]
 *
 * https://www.geeksforgeeks.org/merge-k-sorted-arrays/
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
struct cmp{
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        return a.first>b.first;
    }
};
*/

/*
void mergeK(vector<vector<int>> &A){
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    vector<int> cur(A.size(), 0);
    vector<int> res;

    for(int i=0;i<A.size();i++)
        pq.push({A[i][0], i});

    while(!pq.empty()){
        int num=pq.top().first;
        int row=pq.top().second;
        pq.pop();
        
        res.push_back(num);
        if(++cur[row]<A[row].size()){
            int i=cur[row];
            pq.push({A[row][i], row});
        }
    }

    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    cout<<endl;
}
*/

struct Node{
    int val;
    int array;
    int index;
    Node(int val, int array, int index):val(val),array(array),index(index){}
};

struct cmp{

    bool operator()(Node* a, Node* b){
        return a->val>b->val;
    }
};

void mergeK(vector<vector<int>> &A){

    priority_queue<Node*, vector<Node*>, cmp> pq; 

    for(int i=0;i<A.size();i++){
        Node* cur=new Node(A[i][0], i, 0);
        pq.push(cur);
    }

    vector<int> res;
    while(!pq.empty()){
        Node* cur = pq.top();
        pq.pop();
        
        res.push_back(cur->val);
        
        int index = cur->index;
        int array = cur->array;
        if( index+1 < A[array].size()){
            cur->index +=1;
            cur->val = A[array][index];
            pq.push(cur);
        }

    }

    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    cout<<endl;

}

int main(){
    vector<vector<int>> A;
    A.push_back({1,5,8,9});
    A.push_back({2,3,7,10});
    A.push_back({4,6,11,15});
    A.push_back({9,14,16,19});
    A.push_back({2,4,6,9});

    mergeK(A);
}
