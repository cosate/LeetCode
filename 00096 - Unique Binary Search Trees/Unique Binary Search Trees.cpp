class Solution {
public:
    int numTrees(int n) {
        if(n == 0)
            return 0;
        int *a = new int[n+1];
        a[0] = 1;
        for(int s = 1; s <= n; s++)
        {
            a[s] = 0;
        }
        for(int i = 1; i<=n; i++)
        {
            for(int j = 0; j<i; j++)
            {
                a[i]+= a[j]*a[i-j-1];
            }
        }
        return a[n];
    }
};