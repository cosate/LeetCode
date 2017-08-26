class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows == 0)
            return 0;
        int columns = matrix[0].size();
        if(columns == 0)
            return 0;
        int res = 0;
        vector<int> vec(columns, 0);
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                if(matrix[i][j] == '0')
                    vec[j] = 0;
                else
                    vec[j] = vec[j] + 1;
            }
            res = max(res, maxrec(vec));
        }
        return res;
    }
    
    int maxrec(vector<int>& graph)
    {
        int res = 0;
        int temp = 0;
        stack<int> s;
        s.push(graph[0]);
        for(int i = 1; i < graph.size(); i++)
        {
            if(graph[i] >= s.top())
            {
                s.push(graph[i]);
            }
            else
            {
                while(!s.empty() && graph[i] < s.top())
                {
                    temp++;
                    res = max(res, s.top()*temp);
                    s.pop();
                }
                while(temp > 0)
                {
                    temp--;
                    s.push(graph[i]);
                }
                s.push(graph[i]);
            }
        }
        while(!s.empty())
        {
            temp++;
            res = max(res, s.top()*temp);
            s.pop();
        }
        return res;
    }
};