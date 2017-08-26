class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = 0;
        int n2 = 0;
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(count1 == 0 && count2 == 0)
            {
                count1++;
                n1 = nums[i];
            }
            else if(count1 == 0 && count2 != 0)
            {
                if(nums[i] != n2)
                {
                    count1++;
                    n1 = nums[i];
                }
                else
                    count2++;
            }
            else if(count2 == 0 && count1 != 0)
            {
                if(nums[i] != n1)
                {
                    count2++;
                    n2 = nums[i];
                }
                else
                    count1++;
            }
            else if(nums[i] == n1)
            {
                count1++;
            }
            else if(nums[i] == n2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int> res;
        count1 = 0;
        count2 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == n1)
                count1++;
            if(nums[i] == n2)
                count2++;
        }
        if(count1 > nums.size()/3)
            res.push_back(n1);
        if(count2 > nums.size()/3)
            res.push_back(n2);
        if(res.size() == 2 && res[0] == res[1])
            res.erase(res.begin()+1);
        return res;
    }
};