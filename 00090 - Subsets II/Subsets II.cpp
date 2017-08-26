class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        return subset(nums, len, 0);
    }
    
    vector<vector<int>> subset(vector<int>& nums, int& len, int begin)
    {
        vector<vector<int>> res;
        if(begin == len-1)
        {
            vector<int> temp1;
            vector<int> temp2;
            res.push_back(temp1);
            temp2.push_back(nums[begin]);
            res.push_back(temp2);
            return res;
        }
        else
        {
            
            int dup = 1;
            while(begin < len-1 && nums[begin] == nums[begin+1])
            {
                dup++;
                begin++;
            }
            vector<vector<int>> pre;
            vector<int> temp;
            for(int i = 0; i <= dup; i++)
            {
                pre.push_back(temp);
                temp.push_back(nums[begin]);
            }
            if(begin != len-1)
            {
                vector<int> temp;
                vector<vector<int>> vec = subset(nums, len, begin+1);
                for(int i = 0; i <pre.size(); i++)
                {
                    for(int j = 0; j < vec.size(); j++)
                    {
                        temp.insert(temp.end(), pre[i].begin(), pre[i].end());
                        temp.insert(temp.end(), vec[j].begin(), vec[j].end());
                        res.push_back(temp);
                        temp.clear();
                    }
                }
                return res;
            }
            else
            {
                return pre;
            }
        }
    }
};