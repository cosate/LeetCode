class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int lenp = pattern.length();
        int lens = str.length();
        vector<string> vecstr;
        int tempstart = 0;
        int tempend = 0;
        while(tempend < lens)
        {
            if(str[tempend] == ' ')
            {
                vecstr.push_back(str.substr(tempstart,tempend-tempstart));
                tempstart = tempend+1;
            }
            tempend++;
        }
        vecstr.push_back(str.substr(tempstart,tempend-tempstart));
        if(lenp != vecstr.size())
            return false;
        map<char, string> p2s;
        map<string, char> s2p;
        for(int i = 0; i < lenp; i++)
        {
            if(p2s.count(pattern[i]) == 0 && s2p.count(vecstr[i]) == 0)
            {
                p2s[pattern[i]] = vecstr[i];
                s2p[vecstr[i]] = pattern[i];
            }
            else if(p2s.count(pattern[i]) != 0 && s2p.count(vecstr[i]) != 0)
            {
                if(p2s[pattern[i]] != vecstr[i] || s2p[vecstr[i]] != pattern[i])
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};