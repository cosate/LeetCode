class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> twosummap;
        vector<int> results;
        for(int i = 0; i < nums.size(); i++)
        {
            if(!twosummap.count(nums[i]))
            {
                twosummap.insert(pair<int,int>(nums[i],i));
            }
            if(twosummap.count(target-nums[i]))
            {
                if(twosummap[target-nums[i]]<i)
                {
                    results.push_back(twosummap[target-nums[i]]);
                    results.push_back(i);
                    return results;
                }
            }
            
        }
        return results;
    }
};