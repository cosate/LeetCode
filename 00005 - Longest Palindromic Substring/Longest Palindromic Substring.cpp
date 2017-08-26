class Solution {
public:
    string longestPalindrome(string s) {
       bool memo[s.size()][s.size()];
       int start = 0;
       int end = 0;
       int maxlength = 1;
       
       for(int u = 0;u < s.size();u++)
       {
           for(int v= 0; v<s.size(); v++)
           {
               if(u>=v)
               {
                   memo[u][v] = true;
               }
               else
               memo[u][v] = false;
           }
       }
       for (int j = 1; j < s.size(); j++)
    	{
    		for (int i = 0; i < j; i++)
    		{
    			if (s[i] == s[j] && memo[i+1][j-1] == true)
    			{
    			    memo[i][j] = true;
    				if (j - i + 1 > maxlength)
    				{
    					start = i;
    					end = j;
    					maxlength = j - i + 1;
    				}
    			}
    			else
    			memo[i][j] = false;
    		}
    		
    	}
    	return s.substr(start, maxlength);
    }
};