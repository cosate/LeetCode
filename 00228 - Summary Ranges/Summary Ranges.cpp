class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        vector<string> res;
        if(len == 0)
            return res;
        else if(len == 1)
        {
            res.push_back(generate(nums, 0, 0));
            return res;
        }
        else
        {
            int begin = 0;
            for(int i = 1; i < len; i++)
            {
                if(nums[i] != nums[i-1]+1)
                {
                    res.push_back(generate(nums, begin, i-1));
                    begin = i;
                }
            }
            res.push_back(generate(nums, begin, len-1));
            return res;
        }
    }
    
    string generate(vector<int>& nums, int begin, int end)
    {
        string res = "";
        if(begin == end)
        {
            res += itos(nums[begin]);
        }
        else
        {
            res += itos(nums[begin]);
            res += "->";
            res += itos(nums[end]);
        }
        return res;
    }
    string itos(int num)
    {
        if(num == 0)
            return "0";
        if(num == INT_MIN)
            return "-2147483648";
        string res = "";
        if(num < 0)
        {
            res += "-";
            num = 0-num;
        }
        stack<int> ss;
        while(num != 0)
        {
            ss.push(num%10);
            num = num/10;
        }
        while(!ss.empty())
        {
            res+=(char)(ss.top()+48);
            ss.pop();
        }
        return res;
    }
};