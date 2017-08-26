class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        while(i<len)
        {
            while(nums[i] != i+1 && nums[nums[i]-1] != nums[i])
            {
                int temp = nums[i];
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
            }
            i++;
        }
        vector<int> res;
        for(int i = 0; i<len; i++)
        {
            if(nums[i] != i+1)
                res.push_back(nums[i]);
        }
        return res;
    }
};