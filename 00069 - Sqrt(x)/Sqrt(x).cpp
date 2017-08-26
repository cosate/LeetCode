class Solution {
public:
    int mySqrt(int x) {
        unsigned long long begin = 0;
        unsigned long long end = (x+1)/2;
        unsigned long long mid;
        while(begin < end)
        {
            mid = ((begin+end)/2)*((begin+end)/2);
            if( mid > x)
                end = (begin+end)/2-1;
            else if(mid < x)
                begin = (begin+end)/2+1;
                else
                    return (begin+end)/2;
        }
    if(end*end > x)
        return end-1;
    else
        return end;
    }
};