class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        int i = 0;
        while(i < len)
        {
            while(nums[i] != i+1 && nums[nums[i]-1] != nums[i])
            {
                int temp = nums[i];
                nums[i] = nums[nums[i]-1];
                nums[temp-1]  = temp;
            }
            i++;
        }
        for(int i = 0; i<len ;i++)
        {
            if(nums[i] != i+1)
                res.push_back(i+1);
        }
        return res;
    }
};