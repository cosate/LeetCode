class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string temp = "";
        int len = s.length();
        restore(s, len, res, temp, 0, 1);
        return res;
    }
    
    void restore(string& s, int& len, vector<string>& result, string temp, int begin, int part)
    {
        if(part == 4)
        {
            if(isvalidnum(s, begin, len-1))
            {
                result.push_back(temp+s.substr(begin, len-begin));
            }
        }
        else
        {
            for(int end = begin; end < begin + 3; end++)
            {
                if(end < len && isvalidnum(s, begin, end))
                {
                    restore(s, len, result, temp + s.substr(begin, end-begin+1) + ".", end+1, part+1);
                }
            }
        }
    }
    
    bool isvalidnum(string& strs, int begin, int end)
    {
        if(end < begin)
            return false;
        if(end > begin && strs[begin] == '0')
            return false;
        int res = 0;
        for(int i = begin; i <= end; i++)
        {
            if(res > 255)
                return false;
            res = res*10 + strs[i]-48;
        }
        if(res < 256)
            return true;
        else
            return false;
    }
};