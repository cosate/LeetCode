class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> res;
        if(k > n)
            return res;
        comb(n, k, temp, res, 1);
        return res;
    }
    
    void comb(int n, int k, vector<int> temp, vector<vector<int>>& res, int start)
    {
        if(k > 0)
        {
            for(int i = start; i <= n-k+1; i++)
            {
                temp.push_back(i);
                comb(n, k-1, temp, res, i+1);
                temp.pop_back();
            }
        }
        else
        {
            res.push_back(temp);
        }
    }
};