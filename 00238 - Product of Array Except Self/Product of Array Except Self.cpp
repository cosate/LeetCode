class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> left(len,0);
        left[0] = 1;
        vector<int> right(len,0);
        right[len-1] = 1;
        for(int i = 1; i < len; i++)
        {
            left[i] = left[i-1]*nums[i-1];
        }
        for(int j = len-2; j >= 0; j--)
        {
            right[j] = right[j+1]*nums[j+1];
        }
        vector<int> res(len,0);
        for(int k = 0; k < len; k++)
        {
            res[k] = left[k]*right[k];
        }
        return res;
    }
};