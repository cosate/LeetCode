class Solution {
public:
    bool isValid(string s) {
        map<char, int> mm;
    	mm.insert(pair<char, int>('(', 1));
    	mm.insert(pair<char, int>('[', 2));
    	mm.insert(pair<char, int>('{', 3));
    	mm.insert(pair<char, int>('}', 4));
    	mm.insert(pair<char, int>(']', 5));
    	mm.insert(pair<char, int>(')', 6));
    
    	stack<char> m;
    	m.push('#');
    	int i = 0;
    	while (s[i] != '\0')
    	{
    		if (mm[m.top()] + mm[s[i]] == 7)
    		{
    			m.pop();
    		}
    		else
    		{
    			m.push(s[i]);
    		}
    		i++;
    	}
    	if (m.top() == '#')
    		return true;
    	else
    		return false;
        }
};