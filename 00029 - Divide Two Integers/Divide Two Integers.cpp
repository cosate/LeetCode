class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ret = dividelong(dividend, divisor);
        if(ret > INT_MAX || ret < INT_MIN)
            return INT_MAX;
        return ret;
    }
    
    long long dividelong(long long dividend, long long divisor)
    {
        long long result = 0;
        if(divisor == 0)
            return INT_MAX;
        if(dividend == 0)
            return 0;
            
        if(dividend == INT_MIN)  
        {  
            dividend += abs(divisor);  
            if(divisor == -1)  
            {  
                return INT_MAX;  
            }  
            result++;  
        }
        if(divisor == INT_MIN)
        {
            return result;
        }
        int flag = 1;
        if((dividend<0) ^ (divisor<0))
            flag = -1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        int max = 0;
        while(divisor <= (dividend>>1))
        {
            divisor<<=1;
            max++;
        }
        while(max >= 0)
        {
            if(dividend >= divisor)
            {
                dividend -= divisor;
                result+= 1<<max;
            }
            divisor>>=1;
            max--;
        }
        if(flag == -1)
            return -result;
        else
            return result;
    }
};