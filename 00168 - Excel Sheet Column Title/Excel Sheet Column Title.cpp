class Solution {
public:
    string convertToTitle(int n) {
        string result;
        if(n == 0)
            return result;    
        int x = (n-1)/26;
        int y = (n-1)%26;
        result = convertToTitle(x)+(char)(y+65);
        return result;
    }
};