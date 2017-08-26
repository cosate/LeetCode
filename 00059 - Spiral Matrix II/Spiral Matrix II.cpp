class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        if(n == 0)
            return res;
        else if(n == 1)
        {
            vector<int> vec = {1};
            res.push_back(vec);
            return res;
        }
        else if(n == 2)
        {
            vector<int> vec1 = {1,2};
            vector<int> vec2 = {4,3};
            res.push_back(vec1);
            res.push_back(vec2);
            return res;
        }
        else
        {
            vector<vector<int>> vec = generateMatrix(n-2);
            offset(vec, n);
            vector<int> vec0;
            vector<int> vecn;
            for(int i = 0; i < n; i++)
                vec0.push_back(i+1);
            for(int i = 0; i < n; i++)
                vecn.push_back(3*n-2-i);
            for(int i = 0; i < vec.size(); i++)
            {
                vec[i].insert(vec[i].begin(), 4*(n-1)-i);
                vec[i].push_back(n+i+1);
            }
            res.push_back(vec0);
            for(int i = 0; i < vec.size(); i++)
                res.push_back(vec[i]);
            res.push_back(vecn);
            return res;
        }
    }
    
    void offset(vector<vector<int>>& vec, int n)
    {
        for(int i = 0; i < vec.size(); i++)
        {
            for(int j = 0; j < vec[0].size(); j++)
            {
                vec[i][j] += 4*(n-1);
            }
        }
    }
};