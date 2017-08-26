class Solution {
public:
    int addDigits(int num) {
        if(num == 0)
            return 0;
        while(countdigits(num) != 1)
        {
            num = adddig(num);
        }
        return num;
    }
    int countdigits(int n)
    {
        int res = 0;
        while(n != 0)
        {
            res++;
            n = n/10;
        }
        return res;
    }
    int adddig(int n)
    {
        int res = 0;
        while(n != 0)
        {
            res+=(n%10);
            n = n/10;
        }
        return res;
    }
};