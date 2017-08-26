class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(len == 0)
            return 0;
        int res = decode(s, len, 0);
        return res;
    }
    
    int decode(string& s, int& len, int begin)
    {
        if(begin == len-1)
        {
            if(s[begin] != '0')
                return 1;
            else
                return 0;
        }
        else if(begin == len-2)
        {
            if(s[begin] > '2')
            {
                if(s[begin+1] != '0')
                    return 1;
                else
                    return 0;
            }
            else
            {
                if(s[begin] == '2')
                {
                    if(s[begin+1] < '7' && s[begin+1] > '0')
                        return 2;
                    else
                        return 1;
                }
                else if(s[begin] == '1')
                {
                    if(s[begin+1] != '0')
                        return 2;
                    else
                        return 1;
                }
                else
                    return 0;
            }
        }
        else
        {
            if(s[begin] > '2')
                return decode(s, len, begin+1);
            else
            {
                if(s[begin] == '2')
                {
                    if(s[begin+1] < '7')
                        return decode(s, len, begin+1) + decode(s, len, begin+2);
                    else
                        return decode(s, len, begin+2);
                }
                else if(s[begin] == '1')
                {
                    return decode(s, len, begin + 1) + decode(s, len, begin+2);
                }
                else
                {
                    return 0;
                }
            }
        }
    }
};