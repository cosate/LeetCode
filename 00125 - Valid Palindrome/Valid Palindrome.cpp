class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
    	int i = 0;
    	string temp;
    	while (i <= n-1)
    	{
    		if (s[i] >= 65 && s[i] <= 90)
    		{
    			temp += (s[i] + 32);
    			i++;
    		}
    		else if ((s[i] >= 97 && s[i] <= 122) || (s[i]>=48 && s[i]<=57))
    		{
    			temp += s[i];
    			i++;
    		}
    		else
    			i++;
    	}
    	int j = 0;
    	int l = temp.length();
    	while (j < l/2+1)
    	{
    		if (temp[j] == temp[l - j - 1])
    			j++;
    		else
    			return false;
    	}
    	return true;
    }
};