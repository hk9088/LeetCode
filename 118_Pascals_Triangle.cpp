#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int t[numRows][numRows];
        for(int i=0;i<numRows;i++){
            for(int j=0;j<numRows;j++){
                if(j == 0){
                    t[i][j] = 1;
                }
                else if(i == j){
                    t[i][j] = 1;
                }
                else{
                    t[i][j] = 0;
                }
            }
        }

        for(int i=2;i<numRows;i++){
            for(int j=1;j<i;j++){
                t[i][j] = t[i-1][j] + t[i-1][j-1];
            }
        }

        vector<vector<int>> ans;

        for(int i=0;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                temp.push_back(t[i][j]);
            }
            ans.push_back(temp);
        }

        return ans;
    }

    
};


int main(){
    Solution s;
    s.generate(5);
}
