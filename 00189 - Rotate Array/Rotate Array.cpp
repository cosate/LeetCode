class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n+k,0);
        for(int i = k; i < n+k; i++)
        {
            temp[i] = nums[i-k];
        }
        for(int j = k; j<n+k; j++)
        {
            nums[j%n] = temp[j];
        }
    }
};