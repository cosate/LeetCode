class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int len = nums.size();
        map<int,int> m;
        for(int i = 0; i < len; i++)
        {
            if(m.count(nums[i]) == 0)
                m[nums[i]] = 1;
            else
                ++m[nums[i]];
        }
        
        vector<vector<int>> vec(len);
        for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
        {
            vec[it->second-1].push_back(it->first);
        }
        
        vector<int> res;
        for(int j = len-1; j >= 0; j--)
        {
            if(k <= 0)
                break;
            if(vec[j].size() != 0)
            {
                if(k >= vec[j].size())
                {
                    res.insert(res.end(),vec[j].begin(),vec[j].end());
                }
                else
                {
                    res.insert(res.end(), res.begin(), res.begin()+k);
                }
                k-=vec[j].size();
            }
        }
        return res;
    }
};