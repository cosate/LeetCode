class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> res;
        int rows = triangle.size();
        res = mini(triangle, rows-1);
        int result = INT_MAX;
        for(int i = 0; i < rows; i++)
        {
            if(res[i] < result)
                result = res[i];
        }
        return result;
    }
    
    vector<int> mini(vector<vector<int>>& tri, int row)
    {
        vector<int> res;
        if(row == 0)
        {
            res.push_back(tri[0][0]);
            return res;
        }
        else
        {
            vector<int> vec = mini(tri, row-1);
            for(int i = 0; i < row+1; i++)
            {
                if(i == 0)
                {
                    res.push_back(vec[0]+tri[row][0]);
                }
                else if( i == row)
                {
                    res.push_back(vec[row-1]+tri[row][row]);
                }
                else
                {
                    res.push_back(min(vec[i-1], vec[i]) + tri[row][i]);
                }
            }
        }
        return res;
    }
};