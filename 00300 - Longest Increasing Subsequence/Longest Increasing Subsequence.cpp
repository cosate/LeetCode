class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len < 2)
            return len;
        vector<int> vec(len, 1);
        for(int i = len-2; i >= 0; i--)
        {
            for(int j = i+1; j < len; j++)
            {
                if(nums[i] < nums[j])
                    vec[i] = max(vec[i], vec[j]+1);
            }
        }
        int res = 0;
        for(int i = 0; i < len; i++)
        {
            res = max(res, vec[i]);
        }
        return res;
    }
};