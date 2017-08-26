class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        string originboard(n, '.');
        vector<vector<int>> vec;
        vector<int> temp;
        queen(n, n, temp, vec);
        vector<vector<string>> res(vec.size());
        for(int i = 0; i < vec.size(); i++)
        {
            res[i].resize(n);
            for(int j = 0; j < n; j++)
            {
                res[i][j] = originboard;
                res[i][j][vec[i][j]] = 'Q';
            }
        }
        return res;
    }
    
    bool isOK(vector<int>& vec, int k)
    {
        int len = vec.size();
        for (int i = 0; i < len; i++)
        {
            if (vec[i] == k)
                return false;
            if ((i - vec[i]) == (len - k) || (i + vec[i]) == (len + k))
                return false;
        }
        return true;
    }
    
    void queen(int n, int t, vector<int> temp, vector<vector<int>>& vec)
    {
        if (t > 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (isOK(temp, i))
                {
                    temp.push_back(i);
                    queen(n, t-1, temp, vec);
                    temp.pop_back();
                }
            }
        }
        else
        {
            vec.push_back(temp);
        }
    }
};