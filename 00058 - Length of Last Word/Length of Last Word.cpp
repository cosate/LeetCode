class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int result = 0;
        for(int i = 0; i<s.length();i++)
        {
            if(s[i]!= ' ')
            {
                result++;
            }
            else
            {
                if(i<s.length()-1 && s[i+1] == ' ')
                {
                    continue;
                }
                else if(i != s.length()-1)
                {
                    result = 0;
                }
            }
        }
        return result;
    }
};