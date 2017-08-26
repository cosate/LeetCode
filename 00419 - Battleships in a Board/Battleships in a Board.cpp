class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        int columns = 0;
        if(rows == 0)
            return 0;
        else
            columns = board[0].size();
        if(columns == 0)
            return 0;
        int res = 0;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                if(board[i][j] == 'X' && (i ==0 || board[i-1][j] == '.') && (j == 0 || board[i][j-1] == '.'))
                    res++;
            }
        }
        return res;
    }
};