class Solution {
public:
    int numSquares(int n) {
        if(n == 1)
            return 1;
        else
        {
            vector<int> vec(n+1, 0);
            vec[0] = 0;
            vec[1] = 1;
            for(int i = 2; i <= n; i++)
            {
                if((int)(sqrt(i))*(int)(sqrt(i)) == i)
                    vec[i] = 1;
                else
                {
                    int temp = INT_MAX;
                    for(int j = 1; j*j < i; j++)
                    {
                        temp = min(temp, 1 + vec[i - j*j]);
                    }
                    vec[i] = temp;
                }
            }
            return vec[n];
        }
    }
};