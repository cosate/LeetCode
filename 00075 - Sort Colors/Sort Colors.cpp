class Solution {
public:
    void sortColors(vector<int>& nums) {
        int next0 = 0;
        int next2 = nums.size() - 1;
        for(int i = 0; i <= next2; i++)
        {
            if(nums[i] == 2)
            {
                while(next0 <= next2 && nums[next2] == 2)
                    next2--;
                if(i < next2)
                {
                    swapnum(nums, i, next2);
                    i--;
                    next2--;
                }
            }
            else if(nums[i] == 0)
            {
                while(next0 <= next2 && nums[next0] == 0)
                    next0++;
                if(i > next0)
                {
                    swapnum(nums, i, next0);
                    i--;
                    next0++;
                }
            }
        }
    }
    
    void swapnum(vector<int>& nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};