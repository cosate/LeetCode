class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int firstzero = 0;
        int i = 0;
        while(i<len && nums[i] != 0)
            i++;
        firstzero = i;
        for(int j = i; j < len; j++)
        {
            if(nums[j] != 0)
            {
                nums[firstzero] = nums[j];
                nums[j] = 0;
                firstzero++;
            }
        }
    }
};