class Solution {
public:
   vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> result;
		int n = numbers.size();
		if (n<2)
			return result;
		for (int i = n-1; i>=0; i--)
    	{
    		int x = find(numbers, target - numbers[i]);
    		if ((numbers[i] + numbers[x]) == target && i!=x)
    		{
    			result.push_back(x + 1);
    			result.push_back(i + 1);
    			break;
    		}
    	}
    	if(result[0] > result[1])
    	{
    	    int temp = result[0];
    	    result[0] = result[1];
    	    result[1] = temp;
    	}
		return result;
	}

	int find(vector<int>& nums, int target)
	{
	    int begin = 0, end = nums.size()-1;
		while (begin < end)
		{
			int mid = (begin + end) / 2;
			if (nums[mid] < target)
			{
				begin = mid + 1;
			}
			else if (nums[mid] > target)
			{
				end = mid - 1;
			}
			else
				return mid;
		}
		if (nums[begin] >= target)
			return begin;
		else
			return begin + 1;
    }
};