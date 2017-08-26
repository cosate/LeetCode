class Solution {
public:
    string reverseString(string s) {
        string result;
    	while (s.length() != 0)
    	{
    		int n = s.length();
    		result += s[n - 1];
    		s = s.substr(0, n - 1);
    	}
    	return result;
    }
};