class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int result = nums.size();
        int current = 0;
        for(int i = 1;i < nums.size(); i++)
        {
            if(nums[i] == nums[current])
            {
                result--;
            }
            else
            {
                current++;
                nums[current] = nums[i];
            }
        }
        return result;
    }
};