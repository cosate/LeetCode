class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> vec;
        int lens = s.length();
        int lenp = p.length();
        vector<int> hash1(256,0);
        vector<int> hash2(256,0);
        for(auto ch:p)
        {
            hash1[ch]++;
        }
        for(int i = 0; i < lens; i++)
        {
            hash2[s[i]]++;
            if(i >= lenp)
            {
                hash2[s[i-lenp]]--;
            }
            if(hash1 == hash2)
                vec.push_back(i-lenp+1);
        }
        return vec;
    }
};