class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> s;
        for(int i = 0; i < heights.size(); i++)
        {
            if(s.empty() || s.top() <= heights[i])
                s.push(heights[i]);
            else
            {
                int count = 0;
                while(!s.empty() && s.top() > heights[i])
                {
                    count++;
                    res = max(res, s.top()*count);
                    s.pop();
                }
                while(count >= 0)
                {
                    s.push(heights[i]);
                    count--;
                }
            }
        }
        int len = s.size();
        for(int i = 1; i <= len; i++)
        {
            res = max(res, s.top()*i);
            s.pop();
        }
        return res;
    }
};