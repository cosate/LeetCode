class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int i = 0;
        vector<int> num;
        vector<char> op;
        while(i < input.length())
        {
            if(input[i] < 48)
            {
                op.push_back(input[i]);
                i++;
            }
            else
            {
                int res = 0;
                while(input[i] >= 48)
                {
                    res = res*10 + input[i] - 48;
                    i++;
                }
                num.push_back(res);
            }
        }
        return diff(num, 0, num.size()-1, op);
    }
    
    vector<int> diff(vector<int>& nums, int begin, int end, vector<char>& oper)
    {
        if(begin == end)
        {
            vector<int> vec = {nums[begin]};
            return vec;
        }
        else
        {
            vector<int> res;
            for(int i = begin; i < end; i++)
            {
                vector<int> left = diff(nums, begin, i, oper);
                vector<int> right = diff(nums, i + 1, end, oper);
                for(int j = 0; j < left.size(); j++)
                {
                    for(int k = 0; k < right.size(); k++)
                    {
                        if(oper[i] == '+')
                            res.push_back(left[j] + right[k]);
                        else if(oper[i] == '-')
                            res.push_back(left[j] - right[k]);
                        else
                            res.push_back(left[j] * right[k]);
                    }
                }
            }
            return res;
        }
    }
};