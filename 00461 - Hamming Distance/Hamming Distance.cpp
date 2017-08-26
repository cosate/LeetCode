class Solution {
public:
    int hammingDistance(int x, int y) {
        int w = x^y;
        int count = 0;
        while(w)
        {
            w = w&(w-1);
            count++;
        }
        return count;
    }
};