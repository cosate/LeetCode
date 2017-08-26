class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total = 0;
    	int buydate = 0;
    	for (int i = 0; i < prices.size(); i++)
    	{
    		if (prices[i] < prices[buydate])
    		{
    			buydate = i;
    		}
    		if ((prices[i] - prices[buydate]) > total)
    		{
    			total = prices[i] - prices[buydate];
    		}
    	}
    	return total;
    }
};