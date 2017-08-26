class Solution {
public:
    string addBinary(string a, string b) {
        string result;
    	int m = a.length();
    	int n = b.length();
    	int temp = 0;
    	int i, j;
    	for (i = m - 1, j = n - 1; i >= 0 && j >= 0; i--, j--)
    	{
    		int x = a[i] - 48;
    		int y = b[j] - 48;
    		if ((x + y + temp) > 1)
    		{
    			if ((x + y + temp) == 2) result += '0';
    			else result += '1';
    			temp = 1;
    		}
    		else
    		{
    			if ((x + y + temp) == 1) result += '1';
    			else result += '0';
    			temp = 0;
    		}
    	}
    	if (m == n)
    	{
    	    if(m>1) result+='1';
    	    else
    	    {
    	        if(temp == 1)
    	        {
    	            result+='1';
    	        }
    	    }
    	    reverse(result.begin(),result.end());
    	    return result;
    	}
    	else
    	{
    		if (i != -1)
    		{
    			for (int u = m - n - 1; u >= 0; u--)
    			{
    				int p = a[u] - 48;
    				if (p + temp > 1)
    				{
    					result += '0';
    					temp = 1;
    				}
    				else
    				{
    				    if(p + temp == 1) result += '1';
    				    else result+='0';
    					temp = 0;
    				}
    			}
    		}
    		else
    		{
    			for (int u = n - m - 1; u >= 0; u--)
    			{
    				int p = b[u] - 48;
    				if (p + temp > 1)
    				{
    					result += '0';
    					temp = 1;
    				}
    				else
    				{
    				    if(p + temp == 1) result += '1';
    				    else result+='0';
    					temp = 0;
    				}
    			}
    		}
    	}
    	if (temp == 1)
    	{
    		result += '1';
    	}
    	reverse(result.begin(), result.end());
    	return result;
    }
};