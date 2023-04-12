#include<vector>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int l, int r){
        int m = (l + r)/2;

        if(nums[m] == target){
            return m;
        }

        if(l == r || l > r){
            return -1;
        }

        if(nums[m] > target){
            return binarySearch(nums, target, l, m - 1);
        }
        else{
            return binarySearch(nums, target, m + 1, r);
        }

    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};