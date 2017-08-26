class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.size() == 0)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int n = find(nums,(double)target);
        if(n == nums.size() || nums[n] != target)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        else
        {
            int i = find(nums,target-0.5);
            int j = find(nums,target+0.5);
            result.push_back(i);
            result.push_back(j-1);
            return result;
        }
    }
    
    int find(vector<int>& nums,double target)
    {
        int begin = 0, end = nums.size()-1;
        while(begin < end)
        {
            int mid = (begin+end)/2;
            if((double)nums[mid] < target)
            {
                begin = mid+1;
            }
            else if((double)nums[mid] > target)
            {
                end = mid-1;
            }
            else
                return mid;
        }
        if((double)nums[begin] >= target)
            return begin;
        else
            return begin+1;
    }
};