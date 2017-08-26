class Solution {
public:
    int findNthDigit(int n) {
        int temp = 0;
        int i = 0;
        vector<int> vec = {0,9,189,2889,38889,488889,5888889,68888889,788888889};
        for(i = 8; i >= 0; i--)
        {
            if(n>vec[i])
            {
                temp = vec[i];
                break;
            }
        }
        int k;
        int l = (n-temp)%(i+1);
        if(l == 0)
        {
            k = (n-temp)/(i+1)+power(10,i)-1;
            return k%10;
        }
        else
        {
            k = (n-temp)/(i+1)+power(10,i);
            for(int p = 0; p < i+1-l; p++)
            {
                k/=10;
            }
            return k%10;
        }
    }
    int power(int x, int y)
    {
        if(y == 0)
            return 1;
        int res = x;
        for(int i = 1; i < y; i++)
        {
            res*=x;
        }
        return res;
    }
};