class Solution {
public:
    struct position
    {
        int x;
        int y;
        position(int r, int c)
        {
            x = r;
            y = c;
        }
    };
    
    void solve(vector<vector<char>>& board) {
		int rows = board.size();
		if (rows == 0)
			return;
		int columns = board[0].size();
		if (columns == 0)
			return;

		for (int i = 0; i < columns; i++)
		{
			if (board[0][i] == 'O')
			{
				board[0][i] = '*';
				bfs(board, 0, i);
			}
			if (board[rows - 1][i] == 'O')
			{
				board[rows - 1][i] = '*';
				bfs(board, rows - 1, i);
			}
		}
		for (int i = 0; i < rows; i++)
		{
			if (board[i][0] == 'O')
			{
				board[i][0] = '*';
				bfs(board, i, 0);
			}
			if (board[i][columns - 1] == 'O')
			{
				board[i][columns - 1] = '*';
				bfs(board, i, columns - 1);
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				if (board[i][j] == '*')
					board[i][j] = 'O';
			}
		}
	}

	void bfs(vector<vector<char>>& board, int row, int column)
	{
		queue<position> qq;
		qq.push(position(row, column));
		while (!qq.empty())
		{
			position temp = qq.front();
			qq.pop();
			for (auto p : surround(board, temp))
			{
				qq.push(p);
			}
		}
	}

	vector<position> surround(vector<vector<char>>& board, position p)
	{
		int rows = board.size();
		int columns = board[0].size();
		vector<position> res;
		if (p.x > 0)
		{
			if (board[p.x - 1][p.y] == 'O')
			{
				res.push_back(position(p.x - 1, p.y));
				board[p.x - 1][p.y] = '*';
			}
		}
		if (p.x < rows - 1)
		{
			if (board[p.x + 1][p.y] == 'O')
			{
				res.push_back(position(p.x + 1, p.y));
				board[p.x + 1][p.y] = '*';
			}
		}
		if (p.y > 0)
		{
			if (board[p.x][p.y - 1] == 'O')
			{
				res.push_back(position(p.x, p.y - 1));
				board[p.x][p.y - 1] = '*';
			}
		}
		if (p.y < columns - 1)
		{
			if (board[p.x][p.y + 1] == 'O')
			{
				res.push_back(position(p.x, p.y + 1));
				board[p.x][p.y + 1] = '*';
			}
		}
		return res;
	}
};