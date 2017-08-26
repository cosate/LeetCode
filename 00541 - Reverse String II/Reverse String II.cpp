class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.length();
        int i = 0;
        for(; i+2*k<len;i+=2*k)
        {
            reverse(s,i,i+k-1);
        }
        if(len-i >= k)
            reverse(s,i,i+k-1);
        else
            reverse(s,i,len-1);
        return s;
    }
    
    void reverse(string& s, int begin, int end)
    {
        for(int i = begin; i<(end+begin)/2+1; i++)
        {
            char a = s[i];
            s[i] = s[end+begin-i];
            s[end+begin-i] = a;
        }
    }
};