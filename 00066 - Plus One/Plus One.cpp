class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
    	int temp = 1;
    	int n = digits.size();
    	for (int i = n - 1; i >= 0; i--)
    	{
    		if (digits[i] + temp == 10)
    		{
    			result.push_back(0);
    			temp = 1;
    		}
    		else
    		{
    			result.push_back(digits[i]+temp);
    			temp = 0;
    		}
    	}
    	if (temp == 1) result.push_back(1);
    	reverse(result.begin(), result.end());
    	return result;
    }
};