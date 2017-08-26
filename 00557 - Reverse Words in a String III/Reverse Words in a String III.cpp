class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        int start = 0;
        int end;
        for(int i = 0; i<len; i++)
        {
            if(s[i] == ' ')
            {
                end = i-1;
                reverse(s,start,end);
                start = i+1;
            }
        }
        reverse(s,start,len-1);
        return s;
    }
    void reverse(string& s, int begin, int end)
    {
        for(int i = 0; i<(end-begin+1)/2; i++)
        {
            char temp = s[begin+i];
            s[begin+i] = s[end-i];
            s[end-i] = temp;
        }
    }
};