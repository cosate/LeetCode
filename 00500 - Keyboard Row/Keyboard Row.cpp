class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        set<char> s1 = {'q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P'};
        set<char> s2 = {'a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L'};
        set<char> s3 = {'z','x','c','v','b','n','m','Z','X','C','V','B','N','M'};
        int len = words.size();
        for(int i = 0; i<len; i++)
        {
            if(s1.count(words[i][0]) == 1)
            {
                bool flag = true;
                int l = words[i].length();
                for(int j = 1; j<l; j++)
                {
                    if(s1.count(words[i][j]) == 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag == true)
                {
                    res.push_back(words[i]);
                }
            }
            else if(s2.count(words[i][0]) == 1)
            {
                bool flag = true;
                int l = words[i].length();
                for(int j = 1; j<l; j++)
                {
                    if(s2.count(words[i][j]) == 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag == true)
                {
                    res.push_back(words[i]);
                }
            }
            else if(s3.count(words[i][0]) == 1)
            {
                bool flag = true;
                int l = words[i].length();
                for(int j = 1; j<l; j++)
                {
                    if(s3.count(words[i][j]) == 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag == true)
                {
                    res.push_back(words[i]);
                }
            }
        }
        return res;
    }
};