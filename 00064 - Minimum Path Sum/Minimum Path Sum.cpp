class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0)
            return 0;
        int n = grid[0].size();
        if(n == 0)
            return 0;
        int** memo = new int*[m];
        for(int i = 0; i<m; i++)
        {
            memo[i] = new int[n];
        }
        memo[m-1][n-1] = grid[m-1][n-1];
        for(int i = n-2; i>=0; i--)
        {
            memo[m-1][i] = memo[m-1][i+1] + grid[m-1][i];
        }
        for(int i = m-2; i>=0; i--)
        {
            memo[i][n-1] = memo[i+1][n-1] + grid[i][n-1];
        }
        for(int s = m-2; s>=0; s--)
        {
            for(int t = n-2; t>=0; t--)
            {
                memo[s][t] = grid[s][t]+min(memo[s+1][t], memo[s][t+1]);
            }
        }
        return memo[0][0];
    }
};