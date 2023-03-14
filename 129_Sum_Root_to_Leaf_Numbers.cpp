#include<iostream>
#include<vector>
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
    int ans = 0;

    void getNumbers(int value, TreeNode* r){

        if(r == NULL){
            return;
        }
        
        value = value*10 + r->val; 

        if(r->left == NULL && r->right == NULL){
            ans += value;
            return;
        }

        getNumbers(value, r->left);
        getNumbers(value, r->right);

    }

    int sumNumbers(TreeNode* root) {

        getNumbers(0, root);

        return ans;
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

    cout<<s.sumNumbers(t);

}