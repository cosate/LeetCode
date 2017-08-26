class Solution {
public:
    char findTheDifference(string s, string t) {
        int len = s.length();
        int res = 0;
        for(int i = 0; i<len; i++)
        {
           res = res^s[i];
           res = res^t[i];
        }
        res = res^t[len];
        return (char)res;
    }
};