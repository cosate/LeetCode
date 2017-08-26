class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        for(int i = 0; i < nums.size(); i++)
        {
            vec.push_back(to_string(nums[i]));
        }
        sort(vec.begin(), vec.end(), cmp);
        string res = "";
        for(int i = 0; i < vec.size(); i++)
        {
            res += vec[i];
        }
        if(res[0] == '0')
            res = "0";
        return res;
    }
    
    static bool cmp(string s1, string s2)
    {
        string temp1 = s1+s2;
        string temp2 = s2+s1;
        return temp1>temp2;
    }
};