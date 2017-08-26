class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        if(len == 0)
            return false;
        vector<bool> rec(len +1, false);
        set<string> ss;
        for(int i = 0; i < wordDict.size(); i++)
        {
            ss.insert(wordDict[i]);
        }
        rec[0] = true;
        for(int i = 1; i < len+1; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(rec[j] && ss.count(s.substr(j, i-j)))
                {
                    rec[i] = true;
                    break;
                }
            }
        }
        return rec[len];
    }
};