class Solution {
public:
    bool checkRecord(string s) {
        int counta = 0;
        int countl = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'A')
            {
                counta++;
                if(counta > 1)
                    return false;
            }
            else if(s[i] == 'L')
            {
                if(countl == 0)
                    countl++;
                else if(s[i-1] == 'L')
                {
                    countl++;
                    if(countl > 2)
                        return false;
                }
                else
                    countl = 1;
            }
            else
                countl = 0;
        }
        if(counta <= 1 && countl <= 2)
            return true;
        else
            return false;
    }
};