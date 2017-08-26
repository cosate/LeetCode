class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0)
            return 0;
        if(needle.length() > haystack.length())
            return -1;
        int m = haystack.length();
        int n = needle.length();
        int result = -1;
        bool flag;
        for(int i = 0; i < m-n+1; i++)
        {
            flag = true;
            for(int j = 0; j < n; j++)
            {
                if(haystack[i+j] != needle[j])
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
            {
                result = i;
                break;
            }
        }
        return result;
    }
};