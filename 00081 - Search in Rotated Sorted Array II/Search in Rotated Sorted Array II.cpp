class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())
            return false;
        int pivot = 0;
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i+1] < nums[i])
            {
                pivot = i+1;
                break;
            }
        }
        if(pivot < nums.size())
        {
            reverse(nums.begin(), nums.begin()+pivot);
            reverse(nums.begin()+pivot, nums.end());
            reverse(nums.begin(), nums.end());
        }
        return binary(nums, 0, nums.size()-1, target);
    }
    
    bool binary(vector<int>& vec, int begin, int end, int target)
    {
        while(begin <= end)
        {
            int temp = begin+(end-begin)/2;
            if(vec[temp] == target)
                return true;
            else if(vec[temp] > target)
            {
                end = temp-1;
            }
            else
            {
                begin = temp+1;
            }
        }
        return false;
    }
};