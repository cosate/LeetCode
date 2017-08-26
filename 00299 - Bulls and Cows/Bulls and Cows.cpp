class Solution {
public:
    string getHint(string secret, string guess) {
        string res = "";
        int len = secret.length();
        if(len == 0)
            return "0A0B";
        map<char, int> mm;
        int A = 0;
        int B = 0;
        for(int i = 0; i < len; i++)
        {
            if(secret[i] == guess[i])
                A++;
            else
            {
                if(mm.count(secret[i]) == 0)
                {
                    mm[secret[i]] = 1;
                }
                else
                {
                    mm[secret[i]]++;
                }
            }
        }
        for(int i = 0; i < len; i++)
        {
            if(secret[i] != guess[i])
            {
                if(mm.count(guess[i]) &&  mm[guess[i]] != 0)
                {
                    mm[guess[i]]--;
                    B++;
                }
            }
        }
        res += to_string(A);
        res += "A";
        res += to_string(B);
        res += "B";
        return res;
    }
};