/**
 * Definition for a binary tree node.*/
#include<iostream>
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
    bool checkSymmetric(TreeNode* l, TreeNode* r){

        if(l == NULL || r == NULL){
            return l == r;
        }

        if(l != NULL && r!= NULL && l->val == r->val){
            return checkSymmetric(l->left, r->right) && checkSymmetric(l->right, r->left);
        }
        else{
            return false;
        }
        
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        else
            return checkSymmetric(root->left,root->right);
    }

};

int main(){
    Solution s;

    TreeNode t[3];

    t[2] = TreeNode(2, NULL, NULL);
    t[1] = TreeNode(2, NULL, NULL);

    TreeNode* t2 = &t[2];
    TreeNode* t1 = &t[1];

    t[0] = TreeNode(1, t2, t1);

    cout<<s.isSymmetric(t);

}