class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;;
        vector<int> vec;
        for(int i = 0; s[i]<91 && s[i] > 64; i++)
        {
           result = result*26+s[i] - 64;
        }
        return result;
    }
};