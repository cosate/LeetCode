class Solution {
public:
    int totalNQueens(int n) {
        int sum = 0;
        vector<int> temp;
        queen(n, n, temp, sum);
        return sum;
    }
    
    bool isOK(vector<int>& vec, int k)
    {
        int len = vec.size();
        for (int i = 0; i < len; i++)
        {
            if (vec[i] == k)
                return false;
            if ((i - vec[i]) == (len - k) || (i + vec[i]) == (len + k))
                return false;
        }
        return true;
    }
    
    void queen(int n, int t, vector<int> temp, int& sum)
    {
        if (t > 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (isOK(temp, i))
                {
                    temp.push_back(i);
                    queen(n, t-1, temp, sum);
                    temp.pop_back();
                }
            }
        }
        else
        {
            sum++;
        }
    }
};