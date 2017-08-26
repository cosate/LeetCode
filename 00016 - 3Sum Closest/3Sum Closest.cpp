class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int res = 0;
        int dis = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len-2; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int temp = twosum(nums, i, target-nums[i]) + nums[i];
            if(temp == target)
                return target;
            else
            {
                if(abs(temp-target) < dis)
                {
                    dis = abs(temp-target);
                    res = temp;
                }
            }
        }
        return res;
    }
    
    int twosum(vector<int>& nums, int para, int target)
    {
        int res = 0;
        int i = para+1;
        int j = nums.size()-1;
        int dis = INT_MAX;
        while(i < j)
        {
            int s = nums[i]+nums[j];
            if(s == target)
            {
                return target;
            }
            else if(s < target)
            {
                if(target-s < dis)
                {
                    dis = target - s;
                    res = s;
                }
                ++i;
            }
            else
            {
                if(s-target < dis)
                {
                    dis = s - target;
                    res = s;
                }
                --j;
            }
        }
        return res;
    }
};