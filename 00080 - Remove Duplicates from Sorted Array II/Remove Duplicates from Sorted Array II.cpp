class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len < 3)
            return len;
        int next = 0;
        int record = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
            {
                record++;
            }
            else
            {
                record = 1;
            }
            if(record <= 2)
            {
                next++;
            }
            nums[next] = nums[i];
        }
        return next+1;
    }
};