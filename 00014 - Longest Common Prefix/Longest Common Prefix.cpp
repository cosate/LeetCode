class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
    	int i = 0;
    	bool indicatior = true;
    	if(strs.size() == 0)
    	    return result;
    	else
    	{
        	while (strs[0][i] != '\0')
        	{
        	    int j = 0;
        		for (; j < strs.size(); j++)
        		{
        			if (strs[j][i] != strs[0][i])
        			{
        				indicatior = false;
        				break;
        			}
        		}
        		if (indicatior == false)
        		{
        			break;
        		}
        		else
        		{
        			if ( j != 0)
        			{
        				result += strs[0][i];
        				i++;
        			}
        		}
        	}
    	}
    	return result;
    }
};