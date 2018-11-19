/*
 * Construct BST from given preorder traversal
 *
 * https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/
 *
 */



#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):val(val), left(nullptr), right(nullptr){}
};

void preorderTraverse(TreeNode *root){
    if(!root) return ;
    cout<<root->val<<endl;
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}

TreeNode* toBST(vector<int>& in, TreeNode *min_node, TreeNode *max_node, int& id){
    if(id==in.size())
        return nullptr;

    TreeNode* cur=nullptr;
    if( (!min_node || in[id]>min_node->val) &&  (!max_node || in[id]<max_node->val) ){//build node
        cur=new TreeNode(in[id++]);
        cur->left = toBST(in, min_node, cur, id);
        cur->right = toBST(in, cur, max_node, id);
    }

    return cur;

}

int main(){
    vector<int> preorder{10, 5, 1, 7, 40, 50};
    int id=0;
    TreeNode *root=toBST(preorder, nullptr, nullptr, id);
    preorderTraverse(root);
}
