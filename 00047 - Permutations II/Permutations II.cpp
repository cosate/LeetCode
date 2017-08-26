class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        permu(temp, nums, res);
        return res;
    }
    
    void permu(vector<int> temp, vector<int>& vec, vector<vector<int>>& res)
    {
        if(!vec.empty())
        {
            for(int i = 0; i < vec.size(); i++)
            {
                int t = vec[i];
                if( i > 0 && t == vec[i-1])
                    continue;
                temp.push_back(t);
                vec.erase(vec.begin()+i);
                permu(temp, vec, res);
                vec.insert(vec.begin()+i, t);
                temp.pop_back();
            }
        }
        else
        {
            res.push_back(temp);
        }
    }
};