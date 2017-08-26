class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m == 0)
            return res;
        int n = matrix[0].size();
        if(n == 0)
            return res;
        int x = min(m/2,n/2);
        for(int i = 0; i<x; i++)
        {
            for(int j = i; j<n-i; j++)
            {
                res.push_back(matrix[i][j]);
            }
            for(int j = i+1; j<m-i;j++)
            {
                res.push_back(matrix[j][n-1-i]);
            }
            for(int j = n-2-i; j >= i; j--)
            {
                res.push_back(matrix[m-1-i][j]);
            }
            for(int j = m-i-2; j >= i+1; j--)
            {
                res.push_back(matrix[j][i]);
            }
        }
        if(m%2 || n%2)
        {
            if(m>n)
            {
                if(m/2 != n/2)
                {
                    for(int i = n/2; i<m-n/2; i++)
                    {
                        res.push_back(matrix[i][n/2]);
                    }
                }
            }
            else if(m<n)
            {
                if(m/2 != n/2)
                {
                    for(int i = m/2; i<n-m/2; i++)
                    {
                        res.push_back(matrix[m/2][i]);
                    }
                }
            }
            else
                res.push_back(matrix[m/2][m/2]);
        }
        return res;
    }
};