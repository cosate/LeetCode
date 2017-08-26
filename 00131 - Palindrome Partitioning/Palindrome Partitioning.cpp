class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<string>> res;
        if(len == 0)
            return res;
        else if(len == 1)
        {
            vector<string> temp = {s};
            res.push_back(temp);
            return res;
        }
        for(int i = len-1; i > 0; i--)
        {
            if(ispalindrome(s, i, len-1))
            {
                string temp = s.substr(i, len-i);
                vector<vector<string>> last = partition(s.substr(0,i));
                for(int j = 0; j < last.size(); j++)
                {
                    last[j].push_back(temp);
                    res.push_back(last[j]);
                }
            }
        }
        if(ispalindrome(s, 0, len-1))
        {
            vector<string> temp = {s};
            res.push_back(temp);
        }
        return res;
    }
    
    bool ispalindrome(string& s, int begin, int end)
    {
        while(begin < end)
        {
            if(s[begin] != s[end])
                return false;
            else
            {
                begin++;
                end--;
            }
        }
        return true;
    }
};