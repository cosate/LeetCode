class Solution {
public:
    int arrangeCoins(int n) {
        long long m = sqrt(1.0*n*2);
        if(m*(m+1)/2 < n) m++;
        if(m*(m+1)/2 > n) m--;
        return m;
    }
};