class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n);
        res[0] = 1;
        int f2 = 0, f3 = 0, f5 = 0;
        for(int i = 1; i < n; i++)
        {
            int m2 = res[f2]*2;
            int m3 = res[f3]*3;
            int m5 = res[f5]*5;
            if(m2 <= m3 && m2 <= m5)
            {
                res[i] = m2;
                f2++;
            }
            else if(m3 <= m2 && m3 <= m5)
            {
                res[i] = m3;
                f3++;
            }
            else
            {
                res[i] = m5;
                f5++;
            }
            if(res[i] == res[i-1])
                i--;
        }
        return res[n-1];
    }
};