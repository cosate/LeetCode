class Solution {
public:
    int reverse(int x) {
        long long result = 0;
    	int res = 0;
    	if (x > 0)
    	{
    		while (x / 10 != 0)
    		{
    			result = result * 10 + x % 10;
    			x = x / 10;
    		}
    		result = result * 10 + x;
    		if (result > INT_MAX)
    			res = 0;
    		else
    			res = (int)result;
    	}
    	else
    	{
    	    if(x == INT_MIN)
    	    {
    	        res = 0;
    	    }
    	    else
        	{
        	    //x = 0 - x;
        		while (x / 10 != 0)
        		{
        			result = result * 10 + x % 10;
        			x = x / 10;
        		}
        		result = result * 10 + x;
        		//result = 0 - result;
        		if (result <= INT_MIN)
        			res = 0;
        		else
        			res = (int)result;
        	}
    	}
    	return res;
    }
};