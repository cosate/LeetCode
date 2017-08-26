class Solution {
public:
    string convertToBase7(int num) {
        string res;
        if(num>0)
        {
            while(num != 0)
            {
                int l = num%7;
                res = (char)(l+48)+res;
                num/=7;
            }
            return res;
        }
        else if(num<0)
        {
            res = '-'+convertToBase7(-num);
            return res;
        }
        else
            return "0";
    }
};