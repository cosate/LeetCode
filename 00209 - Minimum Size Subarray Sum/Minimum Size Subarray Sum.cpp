class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        int begin = 0;
        int res = len;
        for(int i = 0; i < len; i++)
        {
            if(sum >= s)
            {
                sum -= nums[begin];
                if(res > i - begin)
                    res = i - begin;
                begin++;
                i--;
            }
            else
            {
                sum += nums[i];
            }
        }
        if(sum < s && res == len)
            return 0;
        while(begin < len && sum-nums[begin] >= s)
        {
            sum -= nums[begin];
            if(res > len - 1 - begin)
                res = len - 1 - begin;
            begin++;
        }
        return res;
    }
};