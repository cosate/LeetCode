class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if(k > n)
            return res;
        else if(k == n)
        {
            if(k > 1)
                return res;
        }
        if(k == 1)
        {
            if(n < 10)
            {
                vector<int> vec = {n};
                res.push_back(vec);
                return res;
            }
            else
                return res;
        }
        else
        {
            for(int i = 1; n - i*k > 0; i++)
            {
                vector<vector<int>> vec = combinationSum3(k-1, n - i*k);
                for(int j = 0; j < vec.size(); j++)
                {
                    if(setoffset(vec[j], i))
                    {
                        vec[j].insert(vec[j].begin(), i);
                        res.push_back(vec[j]);
                    }
                }
            }
            return res;
        }
    }
    
    bool setoffset(vector<int>& vec, int offset)
    {
        for(int i = vec.size() - 1; i >= 0; i--)
        {
            vec[i] += offset;
            if(vec[i] > 9)
                return false;
        }
        return true;
    }
};