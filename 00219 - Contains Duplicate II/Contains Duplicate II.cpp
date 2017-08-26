class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> m;
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            if(m.count(nums[i]) && i-m[nums[i]] <= k)
            {
                return true;
            }
            else
            {
                m[nums[i]] = i;
            }
        }
        return false;
    }
};