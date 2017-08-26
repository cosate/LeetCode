class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int temp = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                temp++;
            }
            else
            {
                if(res<temp)
                    res = temp;
                temp = 0;
            }
        }
        if(res<temp)
            res = temp;
        return res;
    }
};