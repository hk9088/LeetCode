/**
 * Definition for a binary tree node.*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    TreeNode* function(int postStart, int postEnd, int inStart, int inEnd, vector<int>& inorder, vector<int>& postorder){

        if (inStart > inEnd || postStart > postEnd){
            return NULL;
        }

        int rootVal = postorder[postEnd];
        int rootIndex = inStart;
        for(;rootIndex<=inEnd;rootIndex++){
            if(inorder[rootIndex] == rootVal){
                break;
            }
        }

        int leftLen = rootIndex - inStart;
        int rigthLen = inEnd - rootIndex;

        TreeNode* root = new TreeNode(rootVal); 
        root->left = function(postStart, postStart + leftLen - 1, inStart, rootIndex - 1, inorder, postorder);
        root->right = function(postEnd - rigthLen, postEnd - 1, rootIndex + 1, inEnd, inorder, postorder);
        

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        cout<<len<<"\n";
        return function(0, len-1, 0, len-1, inorder, postorder);
    }

    void printTree(TreeNode * root){

        

        TreeNode * l = root->left;
        TreeNode * r = root->right;
        cout<<root->val<<" ";

        if(!l && !r){
            return;
        }
        
        printTree(l);
    }

};

int main(){
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    Solution s;

    TreeNode * root = s.buildTree(inorder, postorder);
    TreeNode * l = root->left;
    TreeNode * r = root->right;

    cout<<root->val<<" "<<l->val<<" "<<r->val;

    s.printTree(root);
}