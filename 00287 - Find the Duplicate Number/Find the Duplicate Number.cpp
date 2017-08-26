class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        if(len < 2)
            return 0;
        int slow = 0;
        int fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        int res = 0;
        while(res != slow)
        {
            res = nums[res];
            slow = nums[slow];
        }
        return res;
    }
};