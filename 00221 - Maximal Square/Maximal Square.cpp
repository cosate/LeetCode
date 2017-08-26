class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows == 0)
            return 0;
        int columns = matrix[0].size();
        if(columns == 0)
            return 0;
        vector<vector<int>> record(rows);
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                record[i].push_back(matrix[i][j] -48);
            }
        }
        
        int res = INT_MIN;
        for(int i = 0; i < rows; i++)
        {
            if(res < record[i][0])
                res = record[i][0];
        }
        for(int j = 0; j < columns; j++)
        {
            if(res < record[0][j])
                res = record[0][j];
        }
        
        for(int i = 1; i < rows; i++)
        {
            for(int j = 1; j < columns; j++)
            {
                if(record[i][j] == 1)
                {
                    int temp = min(record[i-1][j-1], min(record[i-1][j], record[i][j-1]));
                    record[i][j] = temp+1;
                }
                res = max(res, record[i][j]);
            }
        }
        return res * res;
    }
};