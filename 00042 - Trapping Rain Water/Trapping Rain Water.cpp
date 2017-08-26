class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        vector<int> temp = height;
        int n = height.size();
        if(n<3)
            return 0;
        int max = height[0], maxindex = 0;
        for(int i = 1; i<n; i++)
        {
            if(height[i] > max)
            {
                max = height[i];
                maxindex = i;
            }
        }
        int tempmax = height[0];
        for(int s = 0; s<maxindex; s++)
        {
            if(height[s] <tempmax)
            {
                height[s] = tempmax;
            }
            else
            {
                tempmax = height[s];
            }
        }
        tempmax = height[n-1];
        for(int t = n-1; t>maxindex; t--)
        {
            if(height[t] < tempmax)
            {
                height[t] = tempmax;
            }
            else
            {
                tempmax = height[t];
            }
        }
        for(int x = 0; x<n; x++)
        {
            result+=(height[x]-temp[x]);
        }
        return result;
    }
};