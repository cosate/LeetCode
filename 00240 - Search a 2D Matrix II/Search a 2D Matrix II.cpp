class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0)
            return false;
        int columns = matrix[0].size();
        if(columns == 0)
            return false;
        int beginrow = rows-1;
        int begincolumn = 0;
        while(beginrow >= 0 && begincolumn < columns)
        {
            if(matrix[beginrow][begincolumn] > target)
                beginrow--;
            else if(matrix[beginrow][begincolumn] < target)
                begincolumn++;
            else
                return true;
                
        }
        return false;
    }
};