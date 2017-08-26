class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int **row= new int*[m+1];
        for(int i = 0; i<=m; i++)
        {
            row[i] = new int[n];
        }
        int **column = new int*[m];
        for(int i = 0; i<m; i++)
        {
            column[i] = new int[n+1];
        }
        for(int i = 0; i<=m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                row[i][j] = -1;
            }
        }
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<=n; j++)
            {
                column[i][j] = -1;
            }
        }
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    row[i][j] = -row[i][j];
                    row[i+1][j] = -row[i+1][j];
                    column[i][j] = -column[i][j];
                    column[i][j+1] = -column[i][j+1];
                }
            }
        }
        int res = 0;
        for(int i = 0; i<=m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(row[i][j] == 1)
                    res++;
            }
        }
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<=n; j++)
            {
                if(column[i][j] == 1)
                    res++;
            }
        }
        return res;
    }
};