class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.length();
        if(len == 0)
            return -1;
        int res = len+1;
        int a[26];
        memset(a,0,sizeof(a));
        for(int i = 0; i<len; i++)
        {
            a[s[i]-97]++;
        }
        for(int i = 0; i<26; i++)
        {
            if(a[i] == 1 && s.find((char)(i+97))<res)
                res = s.find((char)(i+97));
        }
        if(res>len)
            return -1;
        else
            return res;
    }
};