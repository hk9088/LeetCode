#include<iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = t.length();
        int n = s.length();

        int dp[m+1][n+1];

        for(int i=0;i<m+1;i++)  dp[i][0] = 0;
        for(int j=0;j<n+1;j++)  dp[0][j] = 0;

        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(t[i-1] == s[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        if(n == dp[m][n]){
            return true;
        }
        else{
            return false;
        }



    }
};

int main(){

    Solution s;
    cout<<s.isSubsequence("abc", "ahbgdc");

}