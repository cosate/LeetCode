class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int len = s.length();
        if(len < 11)
            return res;
        
        map<char,int>mp;
        mp['A'] = 0;
        mp['C'] = 1;
        mp['G'] = 2;
        mp['T'] = 3;
        
        map<int,int> cnt;
        int temp = 0;
        for(int i = 0; i < 10; i++)
        {
            temp = temp<<2 | mp[s[i]];
        }
        cnt[temp] = 1;
        
        for(int i = 10; i < len; i++)
        {
            temp = (temp<<2 | mp[s[i]]) & 0xfffff;
            if(cnt.count(temp) == 0)
                cnt[temp] = 1;
            else if(cnt[temp] == 1)
            {
                res.push_back(s.substr(i-9,10));
                cnt[temp]++;
            }     
        }
        return res;
    }
};