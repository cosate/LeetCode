class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m != n)
            return false;
        map<char,char> s2t;
        map<char,char> t2s;
        for(int i = 0; i<m; i++)
        {
            if(s2t.find(s[i]) == s2t.end() && t2s.find(t[i]) == t2s.end())
            {
                s2t.insert(pair<char,char>(s[i],t[i]));
                t2s.insert(pair<char,char>(t[i],s[i]));
            }
            else if(s2t.find(s[i]) != s2t.end() && t2s.find(t[i]) != t2s.end() && s2t[s[i]] == t[i] && t2s[t[i]] == s[i])
            {}
            else
                return false;
        }
        return true;
    }
};