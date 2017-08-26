class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int prefix = 0;
        int max = 0;
        set<int> pre;
        for(int i = 31; i >= 0; i--)
        {
            prefix = prefix | (1<<i);
            for(int j = 0; j < nums.size(); j++)
            {
                pre.insert(nums[j] & prefix);
            }
            
            int temp = max | (1<<i);
            for(set<int>::iterator it = pre.begin(); it != pre.end(); it++)
            {
                if(pre.count(temp^(*it)))
                   max = temp;
            }
            pre.clear();
        }
        return max;
    }
};