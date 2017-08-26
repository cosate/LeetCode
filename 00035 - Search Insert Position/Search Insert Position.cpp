class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return 0;
            else
             return search(nums,0,nums.size()-1,target);
    }
    
    int search(vector<int>& nums,int start,int end,int target)
    {
        if(start == end)
        {
            if(nums[start] == target)
                return start;
            else if(nums[start] < target)
                return start+1;
                else
                    return start;
        }
        else
        {
            if(nums[(start+end)/2] < target)
            {
                 return search(nums,(start+end)/2+1,end,target);
            }
            else
            {
                return search(nums,start,(start+end)/2,target);
            }
        }
    }
};