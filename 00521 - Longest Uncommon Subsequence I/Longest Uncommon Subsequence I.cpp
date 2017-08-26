class Solution {
public:
    int findLUSlength(string a, string b) {
        int len1 = a.length();
        int len2 = b.length();
        if(len1 != len2)
        {
            return len1>len2 ? len1 : len2;
        }
        else
        {
            if(a == b)
                return -1;
            else
                return len1;
        }
    }
};