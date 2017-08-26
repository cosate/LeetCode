class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0)
        {
            return 0;
        }
        int n = obstacleGrid[0].size();
        if(n == 0)
        {
            return 0;
        }
        else
        {
            int ** a = new int* [m];
            for(int i = 0; i<m; i++)
            {
                a[i] = new int[n]();
            }
            
            bool rowFlag = false,columnFlag = false;
            
            for(int s = m-1; s>=0; s--)
            {
                if(rowFlag == false && obstacleGrid[s][n-1] == 0)
                    a[s][n-1] = 1;
                else
                {
                    a[s][n-1] = 0;
                    rowFlag = true;
                }
            }
            for(int t = n-1; t>=0; t--)
            {
                if(columnFlag == false && obstacleGrid[m-1][t] == 0)
                    a[m-1][t] = 1;
                else
                {
                    a[m-1][t] = 0;
                    columnFlag = true;
                }
            }
            
            for(int i = m-2; i>=0; i--)
            {
                for(int j = n-2; j>=0; j--)
                {
                    if(obstacleGrid[i][j] == 0)
                        a[i][j] = a[i+1][j] + a[i][j+1];
                    else
                        a[i][j] = 0;
                }
            }
            return a[0][0];
        }
    }
};