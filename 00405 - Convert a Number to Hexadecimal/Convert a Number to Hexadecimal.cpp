class Solution {
public:
    string toHex(int num) {
        stack<char> s;
        string res = "";
        if(num == 0)
            return "0";
        else if(num > 0)
        {
            while(num!=0)
            {
                int i = num%16;
                if(i < 10)
                {
                    s.push(i+48);
                }
                else
                {
                    s.push(i+87);
                }
                num/=16;
            }
            while(!s.empty())
            {
                res+=s.top();
                s.pop();
            }
            return res;
        }
        else
        {
            int temp = (num & INT_MAX);
            while(temp != 0)
            {
                int i = temp%16;
                if(i < 10)
                {
                    s.push(i+48);
                }
                else
                {
                    s.push(i+87);
                }
                temp/=16;
            }
            int ll = s.size();
            if(ll < 8)
            {
                for(int i = 0; i<(8-ll); i++)
                {
                    s.push('0');
                }
            }
            char k = s.top();
            int t;
            if(97>(int)k)
            {
                t = (int)(k-48) + 8;
            }
            else
            {
                t = (int)(k-87) + 8;
            }
            s.pop();
            if(t<10)
            {
                s.push(t+48);
            }
            else
            {
                s.push(t+87);
            }
            while(!s.empty())
            {
                res+=s.top();
                s.pop();
            }
            return res;
        }
    }
};