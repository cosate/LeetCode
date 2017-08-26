class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if(len == 0)
            return 0;
        int res = 0;
        for(int i = 0; i < len - 1; i++)
        {
            if(citations[len - 1 - i] >= i+1 && citations[len - i - 2] <= i+1)
                res = i + 1;
        }
        if(citations[0] >= len)
            res = len;
        return res;
    }
};