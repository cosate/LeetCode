class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if(len == 0)
            return res;
        for(int i = 0; i < 1<<len; i++)
        {
            vector<int> tmp;
            for(int j = 0; j < len; j++)
            {
                if((i>>j)&1)
                    tmp.push_back(nums[j]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};