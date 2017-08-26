class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        for(int i = 0; i <= num; i++)
        {
            if(i == 0)
            {
                result.push_back(0);
            }
            else if(i == 1)
            {
                result.push_back(1);
            }
            else
            {
                if(i%2 == 0)
                {
                    result.push_back(result[i/2]);
                }
                else
                {
                    result.push_back(result[i-1]+1);
                }
            }
        }
        return result;
    }
};