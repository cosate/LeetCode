class Solution {
public:
    int myAtoi(string str) 
    {
        long long result = 0;
    	int res;
    	int k = 0;
    	for (; str[k] == ' '; k++)
    	{}
    	if (str[k] == '-')
    	{
    		for (int i = k+1; i < str.length(); i++)
    		{
    			if (str[i] >= 48 && str[i] <= 57 && result < INT_MAX && result >INT_MIN)
    				result = result * 10 + str[i] - 48;
    			else
    				break;
    		}
    		result = 0 - result;
    	}
    	else if(str[k] == '+')
    	{
    		for (int i = k+1; i < str.length(); i++)
    		{
    			if (str[i] >= 48 && str[i] <= 57 && result < INT_MAX && result >INT_MIN)
    				result = result * 10 + str[i] - 48;
    			else
    				break;
    		}
    	}
    	else
    	{
    	    for (int i = k; i < str.length(); i++)
    		{
    			if (str[i] >= 48 && str[i] <= 57 && result < INT_MAX && result >INT_MIN)
    				result = result * 10 + str[i] - 48;
    			else
    				break;
    		}
    	}
    	if (result > INT_MAX)
    		res = INT_MAX;
    	else if (result < INT_MIN)
    		res = INT_MIN;
    	else
    		res = (int)result;
    	return res;
    }
};