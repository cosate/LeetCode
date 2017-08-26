class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len = nums.size();
        if(k == 0 || len == 0)
            return false;
        long long diff = (long long)t;
        multiset<long long> mset;
        for(int i = 0; i < len; i++)
        {
            if(mset.size() > k)
            {
                mset.erase((long long)nums[i-k-1]);
            }
            auto it = mset.lower_bound((long long)nums[i] - t);
            if(it != mset.end() && (*it - (long long)nums[i]) <= t)
                return true;
            mset.insert((long long)nums[i]);
        }
        return false;
    }
};