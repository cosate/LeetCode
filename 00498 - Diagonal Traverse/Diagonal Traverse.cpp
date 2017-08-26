class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size();
        int columns = 0;
        if(rows == 0)
            return res;
        else
            columns = matrix[0].size();
        if(columns == 0)
            return res;
        if(rows <= columns)
        {
            bool flag = true;
            for(int sum = 0; sum <= rows+columns-2; sum++)
            {
                if(sum < rows-1)
                {
                    if(flag == true)
                    {
                        for(int j = sum; j >= 0; j--)
                        {
                            res.push_back(matrix[j][sum-j]);
                        }
                        flag = false;
                    }
                    else
                    {
                        for(int j = 0; j <= sum; j++)
                        {
                            res.push_back(matrix[j][sum-j]);
                        }
                        flag = true;
                    }
                }
                else if(sum <= columns-1)
                {
                    if(flag == true)
                    {
                        for(int j = rows-1; j >= 0; j--)
                        {
                            res.push_back(matrix[j][sum-j]);
                        }
                        flag = false;
                    }
                    else
                    {
                        for(int j = 0; j <= rows-1; j++)
                        {
                            res.push_back(matrix[j][sum-j]);
                        }
                        flag = true;
                    }
                }
                else
                {
                    if(flag == true)
                    {
                        for(int j = rows-1; j >= sum-columns+1; j--)
                        {
                            res.push_back(matrix[j][sum-j]);
                        }
                        flag = false;
                    }
                    else
                    {
                        for(int j = sum-columns+1; j <= rows-1; j++)
                        {
                            res.push_back(matrix[j][sum-j]);
                        }
                        flag = true;
                    }
                }
            }
        }
        else
        {
            bool flag = true;
            for(int sum = 0; sum <= rows+columns-2; sum++)
            {
                if(sum < columns-1)
                {
                    if(flag == true)
                    {
                        for(int j = 0; j <= sum; j++)
                        {
                            res.push_back(matrix[sum-j][j]);
                        }
                        flag = false;
                    }
                    else
                    {
                        for(int j = sum; j >= 0; j--)
                        {
                            res.push_back(matrix[sum-j][j]);
                        }
                        flag = true;
                    }
                }
                else if(sum <= rows-1)
                {
                    if(flag == true)
                    {
                        for(int j = 0; j <= columns-1; j++)
                        {
                            res.push_back(matrix[sum-j][j]);
                        }
                        flag = false;
                    }
                    else
                    {
                        for(int j = columns-1; j >= 0; j--)
                        {
                            res.push_back(matrix[sum-j][j]);
                        }
                        flag = true;
                    }
                }
                else
                {
                    if(flag == true)
                    {
                        for(int j = sum-rows+1; j <= columns-1; j++)
                        {
                            res.push_back(matrix[sum-j][j]);
                        }
                        flag = false;
                    }
                    else
                    {
                        for(int j = columns-1; j >= sum-rows+1; j--)
                        {
                            res.push_back(matrix[sum-j][j]);
                        }
                        flag = true;
                    }
                }
            }
        }
        return res;
    }
};