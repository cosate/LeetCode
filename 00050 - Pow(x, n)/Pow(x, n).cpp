class Solution {
public:
    double myPow(double x, int n) {
        if( n == 0 )
            return 1;
        else if(n>0)
        {
            if(n == 1)
            {
                return x;
            }
            else
            {
                if(n%2 == 0)
                {
                    double y = pow(x,n/2);
                    return y*y;
                }
                else
                {
                    double z = pow(x,n/2);
                    return z*z*x;
                }
            }
        }
        else
        {
            if(n == INT_MIN)
            {
                return 1/(pow(x,INT_MAX)*x);
            }
            else
                return 1/pow(x,-n);
        }
    }
};