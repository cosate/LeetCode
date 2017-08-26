class Solution {
public:
	int minMoves(vector<int>& nums) {
	    int len = nums.size();
	    int min = INT_MAX;
		for(int i = 0; i<len; i++)
		{
		    if(nums[i]<min)
		        min = nums[i];
		}
		int res = 0;
		for(int j = 0; j<len; j++)
		{
		    res+=(nums[j]-min);
		}
		return res;
	}
};