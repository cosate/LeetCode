class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n<1)
            return 1;
        for(int i = 0; i<n; i++)
        {
            if(nums[i] > 0 && nums[i] != i+1 && nums[i] <= n && nums[i] != nums[nums[i]-1])
            {
                int temp = nums[i];
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
                i--;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != i+1)
            {
                return i+1;
            }
        }
        return n+1;
    }
};