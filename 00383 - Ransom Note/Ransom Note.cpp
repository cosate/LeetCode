class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len = ransomNote.length();
        for(int i = 0; i<len; i++)
        {
            if(magazine.find(ransomNote[i]) == string::npos)
                return false;
            else
            {
                magazine.erase(magazine.find(ransomNote[i]),1);
            }
        }
        return true;
    }
};