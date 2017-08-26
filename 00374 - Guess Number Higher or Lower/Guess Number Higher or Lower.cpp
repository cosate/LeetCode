// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        while(low<high)
        {
            int mid = (high-low)/2+low;
            int g = guess(mid);
            if(g == 0)
                return mid;
            else if(g == 1)
                low = mid+1;
            else
                high = mid-1;
        }
        return high;
    }
};