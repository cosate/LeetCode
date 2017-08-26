class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int len = nums.size();
        int ab = 0;
        for(int i = 0; i<len; i++)
        {
            ab^=nums[i];
        }
        int first1 = ab&~(ab-1);
        int a = 0;
        for(int i = 0; i<len; i++)
        {
            if(nums[i] & first1)
                a^=nums[i];
        }
        int b = ab^a;
        vector<int> vec;
        vec.push_back(a);
        vec.push_back(b);
        return vec;
    }
};