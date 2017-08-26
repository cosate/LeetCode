class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.length();
        if(len == 0)
            return true;
        bool flag = true;
        if(word[0] >= 97)
        {
            for(int i = 1; i<len; i++)
            {
                if(word[i] <= 90)
                {
                    return false;
                }
            }
        }
        else if(len == 1)
            return true;
            else
            {
                if(word[1] >= 97)
                {
                    for(int i = 2; i<len; i++)
                    {
                        if(word[i] <= 90)
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    for(int i = 2; i<len; i++)
                    {
                        if(word[i] >= 97)
                        {
                            return false;
                        }
                    }
                }
            }
        return true;
    }
};