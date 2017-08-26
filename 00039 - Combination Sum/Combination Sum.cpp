class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        int len = candidates.size();
        vector<vector<int>> res;
        comb(candidates, target, temp, len, res);
        for(int i = 0; i < res.size(); i++)
        {
            sort(res[i].begin(), res[i].end());
        }
        set<vector<int>> se;
        for(int i = 0; i < res.size(); i++)
        {
            se.insert(res[i]);
        }
        vector<vector<int>>vec;
        for( auto s : se)
        {
            vec.push_back(s);
        }
        return vec;
    }
    
    void comb(vector<int>& cand, int target, vector<int> temp, int len, vector<vector<int>>& res)
    {
        if(target > 0)
        {
            for(int i = 0; i < len; i++)
            {
                temp.push_back(cand[i]);
                if(cand[i] == target)
                {
                    res.push_back(temp);
                }
                else
                {
                    comb(cand, target-cand[i], temp, len, res);
                }
                temp.pop_back();
            }
        }
    }
};