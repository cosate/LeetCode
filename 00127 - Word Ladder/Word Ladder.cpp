class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size();
        vector<bool> used(len, false);
        int res = 1;
        queue<string> steps;
        steps.push(beginWord);
        int count = 1;
        while(!steps.empty())
        {
            string temp = steps.front();
            steps.pop();
            count--;
            for(int i = 0; i < len; i++)
            {
                if(!used[i] && onechardiff(temp, wordList[i]))
                {
                    if(wordList[i] == endWord)
                        return ++res;
                    used[i] = true;
                    steps.push(wordList[i]);
                }
            }
            if(count == 0)
            {
                count = steps.size();
                res++;
            }
        }
        return 0;
    }
    
    bool onechardiff(string& a, string& b)
    {
        int len = a.length();
        bool res = false;
        int i = 0;
        for(; i < len; i++)
        {
            if(a[i] != b[i])
            {
                res = true;
                break;
            }
        }
        i++;
        for(; i < len; i++)
        {
            if(a[i] != b[i])
            {
                res = false;
                break;
            }
        }
        return res;
    }
};