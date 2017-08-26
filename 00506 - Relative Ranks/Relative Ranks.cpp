class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int len = nums.size();
        map<int,int> m;
        for(int i = 0; i < len; i++)
        {
            m.insert(pair<int,int>(nums[i],i));
        }
        vector<string> res(len);
        char a[10];
        map<int,int>::iterator it;
        int i = len;
        for(it = m.begin(); it != m.end(); it++)
        {
            if(i == 1)
                res[it->second] = "Gold Medal";
            else if(i == 2)
                res[it->second] = "Silver Medal";
            else if(i == 3)
                res[it->second] = "Bronze Medal";
            else
            {
                sprintf(a,"%d",i);
                string s = a;
                res[it->second] = s;
            }
            i--;
        }
        return res;
    }
};