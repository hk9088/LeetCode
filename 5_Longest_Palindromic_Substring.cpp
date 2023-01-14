#include<iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        bool t[n][n];

        for(int g=0;g<n;g++){
            if(g==0){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(i == j){
                            t[i][j] = 1;
                        }
                        else{
                            t[i][j] = 0;
                        }
                    }
                }
            }
            else if(g==1){
                for(int i=0,j=g;j<n;j++,i++){
                    if(s[i] == s[j]){
                        t[i][j] = 1;
                    }
                }
            }
            else{
                for(int i=0,j=g;j<n;j++,i++){
                    if(s[i] == s[j] && t[i+1][j-1]){
                        t[i][j] = 1;
                    }
                }
            }

        }

        string ans = "";
        int mi,mj,flag = 0;
        for(int g=0;g<n;g++){
            for(int i=0,j=n-1-g;i<=g;i++,j++){
                if(t[i][j]){
                    mi = i;
                    mj = j;
                    flag = 1;
                    break;
                }
            }
            if(flag)    break;
        }

        for(int k=mi;k<=mj;k++)   ans += s[k];
        return ans;
    
        
    }
};

int main(){
    Solution s;
    cout<<s.longestPalindrome("aacabdkacaa");
}