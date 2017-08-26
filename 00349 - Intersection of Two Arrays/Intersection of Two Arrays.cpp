class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> res;
        vector<int> result;
        for(int i = 0; i<nums1.size(); i++)
        {
            for(int j = 0; j<nums2.size(); j++)
            {
                if(nums2[j] == nums1[i])
                {
                    res.insert(nums2[j]);
                    break;
                }
            }
        }
        set<int>::iterator it;
        for(it = res.begin(); it != res.end(); it++)
        {
            result.push_back(*it);
        }
        return result;
    }
};