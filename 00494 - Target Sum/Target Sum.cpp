class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return find(nums,S,0);
    }
    int find(vector<int>& number,int S, int begin)
    {
        int len = number.size();
        if(len == 0)
            return 0;
        else if(begin == len-1)
        {
            if(number[begin] == 0 && S == 0)
                return 2;
            else if(number[begin] == S || number[begin] == -S)
                return 1;
            else
                return 0;
        }
        else
        {
            return find(number,S+number[begin],begin+1)+find(number,S-number[begin],begin+1);
        }
    }
};