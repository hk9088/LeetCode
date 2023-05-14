class Solution {
public:
    int guessNumber(int n) {
        
        int l = 1;
        int r = n;

        int mid, num;

        while(l<=r){
            mid = l + (r - l)/2;
            num = guess(mid);

            if(num == 0){
                break;
            }
            else if(num == -1){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return mid;
    }
};
