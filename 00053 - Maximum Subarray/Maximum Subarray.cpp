class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
        {
            return 0;
        }
        int local = nums[0];
        int global = nums[0];
        for(int i = 1; i<n; i++)
        {
            if(local + nums[i] > nums[i])
                local = local+nums[i];
            else
                local = nums[i];
            if(global < local)
                global = local;
        }
        return global;
    }
};