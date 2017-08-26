class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n;
        if(m == 0)
            return false;
        else
        {
            n = matrix[0].size();
        }
        if(n == 0)
        {
            return false;
        }
        
        int row = 0, column = 0;
        
        int begin = 0, end = m-1;
        if(begin != end)
        {
            while(begin <= end)
            {
                int mid = (begin+end)/2;
                if(matrix[mid][0] < target)
                    begin = mid+1;
                else if(matrix[mid][0] > target)
                    end = mid-1;
                else
                    return true;
            }
            row = end;
        }
        
        if(row == -1)
            return false;
        
        begin = 0;
        end = n-1;
        while(begin <= end)
        {
            int mid = (begin+end)/2;
            if(matrix[row][mid] < target)
                begin = mid+1;
            else if(matrix[row][mid] > target)
                end = mid-1;
            else
                return true;
        }
        return false;
    }
};