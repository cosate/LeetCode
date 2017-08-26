class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0)
            return 0;
        int n = nums.size();
        set<pair<int,int>> s;
        for(int i = 0; i < n-1; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(nums[i] - nums[j] == k)
                {
                    s.insert(pair<int,int>(nums[i],nums[j]));
                }
                else if(nums[j] - nums[i] == k)
                {
                    s.insert(pair<int,int>(nums[j],nums[i]));
                }
            }
        }
        return s.size();
    }
};