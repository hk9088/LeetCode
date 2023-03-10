#include<iostream>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        int arr[38];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;

        if(n < 3){
            return arr[n];
        }
        else{
            for(int i=3;i<=n;i++){
                arr[i] = arr[i-1] + arr[i-2] + arr[i - 3];
            }
            return arr[n];
        }
        
    }
    
};

int main(){
    Solution s;
    cout<<s.tribonacci(25);
}