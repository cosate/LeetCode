class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        if(len == 1)
            return nums[0];
        int maxwithendofi;
        int minwithendofi;
        int res = nums[0];
        int maxlast = nums[0];
        int minlast = nums[0];
        for(int i = 1; i < len; i++)
        {
            maxwithendofi = max(nums[i], max(maxlast*nums[i], minlast*nums[i]));
            minwithendofi = min(nums[i], min(maxlast*nums[i], minlast*nums[i]));
            maxlast = maxwithendofi;
            minlast = minwithendofi;
            res = max(res, maxlast);
        }
        return res;
    }
};