class Solution {
public:
    string convert(string s, int numRows) 
    {
        string str;
    	string *strArray = new string[numRows];
    	if(numRows == 1)
    	{
    	    str = s;
    	}
    	else
    	{
        	for (int i = 0; i < s.size(); i++)
        	{
        		if ((i % (2 * numRows - 2)) < numRows)
        		{
        			strArray[i % (2 * numRows - 2)] += s[i];
        		}
        		else
        		{
        			strArray[(2 * numRows - 2) - i % (2 * numRows - 2)] += s[i];
        		}
        	}
        	for (int j = 0; j < numRows; j++)
        	{
        		str += strArray[j];
        	}
    	}
    	return str;
    }
};