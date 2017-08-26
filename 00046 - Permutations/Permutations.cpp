class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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