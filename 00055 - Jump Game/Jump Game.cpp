class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return false;
        else
        {
            vector<bool> flag(n,false);
            flag[0] = true;
            for(int i = 0; i<n; i++)
            {
                if(flag[i] == true)
                {
                    if(i == 0 || nums[i]>=nums[i-1])
                    {
                        for(int j = 1; j <= nums[i] && i+j<n; j++)
                        {
                            flag[i+j] = true;
                        }
                    }
                }
                else
                    break;
            }
            return flag[n-1];
        }
    }
};