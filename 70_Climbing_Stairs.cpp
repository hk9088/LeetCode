#include<iostream>
using namespace std;

class Solution {
public:
    int t[1001];
    int solve(int n){
        if(n == 0){
            return 1;
        }
        if(n < 0){
            return 0;
        }
        if(t[n]){
            return t[n];
        }
        else{
            return t[n] = solve(n-1) + solve(n-2);
        }
      
    }
    int climbStairs(int n) {
        for(int i=0;i<n;i++)    t[i]=0;
        return solve(n);
    }
};

int main(){
    Solution s1;
    cout<<s1.climbStairs(3);
}