#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int t[10001];
    bool solve(vector<int>& nums, int i){
        if(t[i] != -1){
            return t[i];
        }
        if(nums[i] == 0 && i < nums.size() - 1){
            return t[i] = false;
        }
        if(i + nums[i] >= (nums.size() - 1)){
            return true;
        }
        else{
            while(nums[i]){
                if(solve(nums, i + nums[i])){
                    return t[i] = true;
                }
                else{
                    nums[i]--;
                    solve(nums, i + nums[i]);
                }
            }
        }
        return false;

    }
    bool canJump(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            t[i] = -1;
        }
        return solve(nums, 0);
    }
};

int main(){
    Solution s1;
    vector<int>v = {3,2,1,0,4};
    cout<<s1.canJump(v);
}