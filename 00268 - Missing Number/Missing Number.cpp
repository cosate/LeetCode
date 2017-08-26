class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        while(i<len)
        {
            while(nums[i] != i && nums[nums[i]] != nums[i] && nums[i] != len)
            {
                int temp = nums[i];
                nums[i] = nums[nums[i]];
                nums[temp] = temp;
            }
            i++;
        }
        for(int i = 0; i<len; i++)
        {
            if(nums[i] != i)
                return i;
        }
        return len;
    }
};