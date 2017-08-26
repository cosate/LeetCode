class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int index = len-1;
        for(; index > 0; index--)
        {
            if(nums[index] > nums[index-1])
                break;
        }
        if(index == 0)
            sort(nums.begin(), nums.end());
        else
        {
            int change = index;
            for(; change < len; change++)
            {
                if(nums[change] <= nums[index-1])
                    break;
            }

            int temp = nums[change-1];
            nums[change-1] = nums[index-1];
            nums[index-1] = temp;

            sort(nums.begin()+index, nums.end());
        }
    }
};