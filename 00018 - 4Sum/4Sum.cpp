class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> result;
        if(len < 4)
            return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len-3; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1; j < len-2; j++)
            {
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                vector<vector<int>> vec = twosum(nums, j, target-nums[i]-nums[j]);
                for(auto it : vec)
                {
                    it.insert(it.begin(), nums[j]);
                    it.insert(it.begin(), nums[i]);
                    result.push_back(it);
                }
            }
        }
        return result;
    }
    
    vector<vector<int>> twosum(vector<int>& nums, int para, int target)
    {
        int i = para+1;
        int j = nums.size()-1;
        vector<vector<int>> res;
        vector<int> temp;
        while(i < j)
        {
            int s = nums[i] + nums[j];
            if(s == target)
            {
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                res.push_back(temp);
                temp.clear();
                while(i < j && nums[i+1] == nums[i] && nums[j-1] == nums[j])
                {
                    ++i;
                    --j;
                }
                ++i;
                --j;
            }
            else if(s < target)
            {
                ++i;
            }
            else
            {
                --j;
            }
        }
        
        return res;
    }
};