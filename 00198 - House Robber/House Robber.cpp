class Solution {
public:
    int rob(vector<int>& nums) {
        int houses = nums.size();
        if(houses == 0)
            return 0;
        if(houses == 1)
            return nums[0];
        if(houses == 2)
            return max(nums[0],nums[1]);
        vector<int> v1(houses,0);
        v1[0] = nums[0];
        v1[1] = max(nums[0],nums[1]);
        for(int i = 2; i < houses; i++)
        {
            v1[i] = max(v1[i-2]+nums[i],v1[i-1]);
        }
        return v1[houses-1];
    }
};