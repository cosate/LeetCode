class Solution {
public:
    int countSegments(string s) {
        int len = s.length();
        int i = 0;
        int res = 0;
        while(s[i] == ' ')
            i++;
        while(i < len)
        {
            while(i < len && s[i] != ' ')
                i++;
            while(i < len && s[i] == ' ' )
                i++;
            res++;
        }
        return res;
    }
};