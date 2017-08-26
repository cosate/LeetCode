class Solution {
public:
    string reverseVowels(string s) {
        vector<bool> vec(s.length(),false);
        string temp = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                temp+=s[i];
                vec[i] = true;
            }
        }
        int l = temp.length();
        for(int j = 0; j < l/2; j++)
        {
            char t = temp[j];
            temp[j] = temp[l-1-j];
            temp[l-1-j] = t;
        }
        int m = 0;
        string res = "";
        for(int k = 0; k < s.length(); k++)
        {
            if(vec[k] == true)
            {
                res += temp[m];
                m++;
            }
            else
            {
                res += s[k]; 
            }
        }
        return res;
    }
};