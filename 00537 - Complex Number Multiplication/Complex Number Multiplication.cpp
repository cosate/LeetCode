class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ra = getreal(a);
        int ia = getimagine(a);
        int rb = getreal(b);
        int ib = getimagine(b);
        int rr = ra*rb-ia*ib;
        int ir = ra*ib+ia*rb;
        char s[10];
        sprintf(s,"%d",rr);
        char t [10];
        sprintf(t,"%d",ir);
        string ss = s;
        string tt = t;
        return ss+"+"+tt+"i";
    }
    int getreal(string a)
    {
        int i = 0;
        int result = 0;
        bool flag = true;
        while(a[i] != '+')
        {
            if(a[i] == '-')
            {
                flag = false;
            }
            else
            {
                result = 10*result+a[i]-48;
            }
            i++;
        }
        if(flag == false)
            result = -result;
        return result;
    }
    int getimagine(string a)
    {
        int i = 0;
        int result = 0;
        bool flag = true;
        while(a[i] != '+')
        {
            i++;
        }
        i++;
        while(a[i] != 'i')
        {
            if(a[i] == '-')
            {
                flag = false;
            }
            else
            {
                result = result*10+a[i]-48;
            }
            i++;
        }
        if(flag == false)
            result = -result;
        return result;
    }
};