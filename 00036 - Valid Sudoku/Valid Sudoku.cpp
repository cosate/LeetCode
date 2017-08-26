class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> row;
        set<char> column;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    if(row.count(board[i][j]) != 0)
                        return false;
                    else
                        row.insert(board[i][j]);
                }
                if(board[j][i] != '.')
                {
                    if(column.count(board[j][i]) != 0)
                        return false;
                    else
                        column.insert(board[j][i]);
                }
            }
            row.clear();
            column.clear();
        }
        for(int i = 0; i < 9; i++)
        {
            if(!isvalid(board, i))
                return false;
        }
        return true;
    }
    
    bool isvalid(vector<vector<char>>& board, int index)
    {
        int startrow = (index/3)*3;
        int startcolumn = (index%3)*3;
        set<char> ss;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i+startrow][j+startcolumn] != '.')
                {
                    if(ss.count(board[i+startrow][j+startcolumn]) != 0)
                        return false;
                    else
                        ss.insert(board[i+startrow][j+startcolumn]);
                }
            }
        }
        return true;
    }
};