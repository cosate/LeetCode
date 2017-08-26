class Solution {
public:
    string addStrings(string num1, string num2) {
        stack<int> s1;
        stack<int> s2;
        int carry = 0;
        stack<int> result;
        int len1 = num1.length();
        int len2 = num2.length();
        for(int i = 0; i<len1; i++)
        {
            s1.push(num1[i]-48);
        }
        for(int i = 0; i<len2; i++)
        {
            s2.push(num2[i]-48);
        }
        while(!s1.empty() && !s2.empty())
        {
            int s = (s1.top()+s2.top()+carry)%10;
            carry = (s1.top()+s2.top()+carry)/10;
            result.push(s);
            s1.pop();
            s2.pop();
        }
        if(s1.empty() && s2.empty())
        {
            if(carry!=0)
                result.push(carry);
        }
        else if(s1.empty())
        {
            while(!s2.empty())
            {
                int s = (s2.top()+carry)%10;
                carry = (s2.top()+carry)/10;
                result.push(s);
                s2.pop();
            }
            if(carry!=0)
                result.push(carry);
        }
        else
        {
            while(!s1.empty())
            {
                int s = (s1.top()+carry)%10;
                carry = (s1.top()+carry)/10;
                result.push(s);
                s1.pop();
            }
            if(carry!=0)
                result.push(carry);
        }
        string res;
        while(!result.empty())
        {
            res+=(char)(result.top()+48);
            result.pop();
        }
        return res;
    }
};