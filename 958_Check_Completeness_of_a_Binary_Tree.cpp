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
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        queue<TreeNode*> nodes; 
        nodes.push(root);
        
        while (!nodes.empty()){
            TreeNode* n = nodes.front();
            nodes.pop();

            if(!n){
                nodes.push(n->left);
                nodes.push(n->right);
            }
            else{
                while (!nodes.empty()){
                    if(nodes.front()){
                        return false;
                    }
                }
            }
        }
        return true;
            
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

    cout<<s.isCompleteTree(t);

}