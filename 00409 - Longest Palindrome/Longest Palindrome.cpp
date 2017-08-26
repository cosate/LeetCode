class Solution {
public:
    int longestPalindrome(string s) {
        int a[128];
        memset(a,0,sizeof(a));
        int len = s.length();
        for(int i = 0; i<len; i++)
        {
            a[s[i]]++;
        }
        int result = 0;
        int maxodd = 0;
        int flag = 0;
        for(int i = 0; i<128; i++)
        {
            if(a[i]%2 == 0)
                result+=a[i];
            else
            {
                result+=(a[i]-1);
                flag = 1;
            }
        }
        result+=flag;
        return result;
    }
};