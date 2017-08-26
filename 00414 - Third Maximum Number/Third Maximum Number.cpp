class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
		int firstmax = nums[0];
		int secondmax = nums[0];
		int thirdmax = nums[0];
		for (int i = 0; i<n; i++)
		{
			if (nums[i]>=firstmax)
			{
				firstmax = nums[i];
			}
			else
			{
				secondmax = nums[i];
			}
		}
		for (int i = 0; i<n; i++)
		{
			if (nums[i] < firstmax)
			{
				if (nums[i] >= secondmax)
				{
					secondmax = nums[i];
				}
				else
				{
					thirdmax = nums[i];
				}
			}
		}
		if (secondmax<firstmax)
		{
			for (int i = 0; i<n; i++)
			{
				if (nums[i] < secondmax && nums[i]>thirdmax)
				{
					thirdmax = nums[i];
				}
			}
			if (thirdmax<secondmax)
				return thirdmax;
			else
				return firstmax;
		}
		else
			return firstmax;
	}
};