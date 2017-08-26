class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> vec;
        int res = 0;
        for(int i = 0; i < words.size(); i++)
        {
            int bits = 0;
            for(int j = 0; j < words[i].length(); j++)
            {
                bits = bits | (1<<(words[i][j] - 'a'));
            }
            vec.push_back(bits);
        }
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = i+1; j < words.size(); j++)
            {
                if(((vec[i] & vec[j]) == 0) && ((words[i].length())*(words[j].length())) > res)
                    res =( words[i].length())*(words[j].length());
            }
        }
        return res;
    }
};