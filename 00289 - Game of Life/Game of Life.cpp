class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        rows = board.size();
        if(rows == 0)
            return;
        columns = board[0].size();
        if(columns == 0)
            return;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                board[i][j] = change(board, i, j);
            }
        }
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                board[i][j] = board[i][j]/2;
            }
        }
    }
    
    int change(vector<vector<int>>& board, int x, int y)
    {
        int count = 0;
        int res = board[x][y];
        if(y > 0)
            count += board[x][y-1] % 2;
        if(y < columns-1)
            count += board[x][y+1] % 2;
        if(x > 0)
        {
            count += board[x-1][y]%2;
            if(y > 0)
                count += board[x-1][y-1]%2;
            if(y < columns -1)
                count += board[x-1][y+1]%2;
        }
        if(x < rows-1)
        {
            count += board[x+1][y]%2;
            if(y > 0)
                count += board[x+1][y-1]%2;
            if(y < columns-1)
                count += board[x+1][y+1]%2;
        }
        if(res % 2 == 1)
        {
            if(count >= 2 && count <= 3)
                res = 3;
            else
                res = 1;
        }
        else
        {
            if(count == 3)
                res = 2;
            else
                res = 0;
        }
        return res;
    }
    
    int rows;
    int columns;
};