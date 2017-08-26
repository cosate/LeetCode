class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int bits[32];
        for(int i = 0; i < 32; i++)
        {
            bits[i] = 0;
        }
        
        for(int x = 0; x < 32; x++)
        {
            for(int y = 0; y < n; y++)
            {
                bits[x] += ((nums[y]>>x) & 1);
            }
        }
        
        for(int i = 0; i < 32; i++)
        {
            res+=((n-bits[i])*bits[i]);
        }
        return res;
    }
};