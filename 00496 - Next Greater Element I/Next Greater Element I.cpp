class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        int m = findNums.size();
        int n = nums.size();
        for(int i = 0; i<m; i++)
        {
            bool flag = false;
            for(int j = 0; j<n; j++)
            {
                if(flag == false)
                {
                    if(nums[j] == findNums[i])
                        flag = true;
                }
                else
                {
                    if(nums[j] > findNums[i])
                    {
                        res.push_back(nums[j]);
                        break;
                    }
                }
                if(j == n-1)
                    res.push_back(-1);
            }
        }
        return res;
    }
};