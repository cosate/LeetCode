class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0)
        {
            return 0;
        }
        if(m == 1 || n == 1)
        {
            return 1;
        }
        else
        {
            int max = 0;
            if(m>n)
                max = m;
            else
                max = n;
            int **a = new int*[max]();
            for(int t = 0; t<max;t++)
            {
                a[t] = new int[max]();
            }
            a[0][0] = 1;
            for(int s=1; s<max; s++)
            {
                a[0][s] = 1;a[s][0] = 1;
            }
            for(int i = 0; i< max; i++)
            {
                for(int j = i; j<max; j++)
                {
                    if(a[i][j] == 0)
                    {
                        a[i][j] = a[i-1][j]+a[i][j-1];
                        a[j][i] = a[i-1][j]+a[i][j-1];
                    }
                }
            }
            return a[m-1][n-1];
        }
    }
};