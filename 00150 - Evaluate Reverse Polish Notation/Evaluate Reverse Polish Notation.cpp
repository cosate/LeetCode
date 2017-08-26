class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(isnum(tokens[i]))
                nums.push(stoi(tokens[i]));
            else
            {
                int re = 0;
                int n2 = nums.top();
                nums.pop();
                int n1 = nums.top();
                nums.pop();
                if(tokens[i][0] == '+')
                    re = n1 + n2;
                else if(tokens[i][0] == '-')
                    re = n1 - n2;
                else if(tokens[i][0] == '*')
                    re = n1 * n2;
                else
                    re = n1 / n2;
                nums.push(re);
            }
        }
        return nums.top();
    }
    
    bool isnum(string s)
    {
        if(s.length() == 1 && (s[0] < 48 || s[0] > 57))
            return false;
        return true;
    }
    
    int stoi(string s)
    {
        int res = 0;
        if(s[0] == '-')
        {
            for(int i = 1; i < s.length(); i++)
            {
                res = res*10 + s[i] - 48;
            }
            return (0 - res);
        }
        else
        {
            for(int i = 0; i < s.length(); i++)
            {
                res = res*10 + s[i] - 48;
            }
            return res;
        }
    }
};