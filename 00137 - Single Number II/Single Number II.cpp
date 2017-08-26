class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        for(int i = 0; i < 32; i++)
        {
            int count1bits = 0;
            for(int j = 0; j < len; j++)
            {
                count1bits += ((nums[j]>>i)&1);
            }
            if(count1bits%3 != 0)
                res = (1<<i) +res;
        }
        return res;
    }
};