#include<iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        int mx = 0, ml, mr;
        int l,r;

        for(int i=0;i<n;i++){
            l = i;
            r = i;
            while (l>=0 && r<n)
            {
                if(s[l] == s[r]){
                    if(r-l+1 > mx){  
                        mx = r - l + 1;
                        ml = l;
                        mr = r;
                    }
                }
                else{
                    break;
                }
                l--;
                r++;
            }
        }

        for(int i=0;i<n;i++){
            l = i;
            r = i+1;
            while (l>=0 && r<n)
            {
                if(s[l] == s[r]){
                    if(r-l+1 > mx){  
                        mx = r - l + 1;
                        ml = l;
                        mr = r;
                    }
                }
                else{
                    break;
                }
                l--;
                r++;
            }
        }
        
        string ans = "";
        for(int i=ml;i<=mr;i++)     ans += s[i];

        return ans;
    }
};

int main(){
    Solution s;
    cout<<s.longestPalindrome("aacabdkacaa");
}