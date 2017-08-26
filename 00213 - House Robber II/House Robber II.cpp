class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        if(len == 1)
            return nums[0];
        return max(robber(nums, 0, len-2), robber(nums, 1, len-1));
    }
    
    int robber(vector<int>& nums, int begin, int end)
    {
        if(end < begin)
			return 0;
		int len = end - begin + 1;
		if(len == 1)
			return nums[begin];
		if(len == 2)
			return max(nums[begin], nums[end]);
		vector<int> res(len);
		res[0] = nums[begin];
		res[1] = max(nums[begin], nums[begin+1]);
		for (int i = 2 ; i < len; i++)
		{
			res[i] = max(res[i - 2] + nums[i + begin], res[i - 1]);
		}
		return res[len-1];
	}
};