class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len  = s.length();
        for(int i = 2; i <= len; i++)
        {
            if(len%i == 0)
            {
                string sub = s.substr(0,len/i);
                string temp = "";
                for(int j = 0; j < i; j++)
                {
                    temp += sub;
                }
                if(temp == s)
                    return true;
            }
        }
        return false;
    }
};