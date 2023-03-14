#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int n = s.size();
        int l = 0, r = n-1;

        while (l<n && r>=0)
        {
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        
        return true;
    }
};

int main(){
    Solution s;
    cout<<s.isPalindrome(-12221);
}