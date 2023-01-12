#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    int t[100006];
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n+1;i++){
            t[i] = -1;
        }
        for(int i=0;i<=n;i++){
            ans.push_back(solve(i));
        }
        return ans;
    }

    int solve(int n){

        if(n == 0){
            return 0;
        }
        if(t[n] != -1){
            return t[n];
        }

        int x = log2(n);
        x = 1<<x;

        return t[n] = 1 + solve(n-x);
    }
};

int main()
{
    Solution s;
    vector<int>ans = s.countBits(15);
    for(auto i: ans){
        cout<<i<<" ";
    }
}