class Solution {
public:
    string frequencySort(string s) {
        int ch[256];
        for(int i = 0; i < 256; i++)
        {
            ch[i] = 0;
        }
        for(int j = 0; j < s.length(); j++)
        {
            ch[s[j]]++;
        }
        string res = "";
        vector<string> vec(s.length()+1,"");
        for(int k = 0; k < 256; k++)
        {
            if(ch[k] != 0)
            {
                vec[ch[k]].append(ch[k],(char)k);
            }
        }
        for(int g = s.length(); g > 0; g--)
        {
            res+=vec[g];
        }
        return res;
    }
};