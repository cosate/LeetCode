class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
    	int j = height.size() - 1;
    	int maxarea = min(height[i], height[j])* (j-i);
    	while (i < j)
    	{
    		if (height[i] < height[j])
    		{
    			++i;
    			maxarea = max(maxarea, min(height[i], height[j])* (j-i));
    		}
    		else
    		{
    			--j;
    			maxarea = max(maxarea, min(height[i], height[j])* (j-i));
    		}
    	}
    	return maxarea;
    }
};