class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        if(rows == 0)
            return false;
        int columns = board[0].size();
        int len = word.length();
        setpass(passed, rows, columns);
        return wordsearch(board, word, 0, len, -1, -1);
    }
    
    bool wordsearch(vector<vector<char>>& board, string& word, int t, int len, int lastx, int lasty)
    {
        if(t == len)
            return true;
        else
        {
            vector<vector<int>> vec = find(board, word[t], lastx, lasty);
            if(vec.size() != 0)
            {
                for(int i = 0; i < vec.size(); i++)
                {
                    if(passed[vec[i][0]][vec[i][1]])
                        continue;
                    passed[vec[i][0]][vec[i][1]] = true;
                    if(wordsearch(board, word, t+1, len, vec[i][0], vec[i][1]))
                        return true;
                    else
                        passed[vec[i][0]][vec[i][1]] = false;
                }
                return false;
            }
            else
                return false;
        }
    }
    
    vector<vector<int>> find(vector<vector<char>>& board, char c, int x, int y)
    {
        int rows = board.size();
        int columns = board[0].size();
        vector<vector<int>> res;
        vector<int> temp;
        if(x == -1 && y == -1)
        {
            for(int i=0; i < board.size(); i++)
            {
                for(int j = 0; j < board[i].size(); j++)
                {
                    if(board[i][j] == c)
                    {
                        temp.push_back(i);
                        temp.push_back(j);
                        res.push_back(temp);
                        temp.clear();
                    }
                }
            }
        }
        else
        {
            if (x >= 1)
			{
				if (board[x - 1][y] == c)
				{
					temp.push_back(x - 1);
					temp.push_back(y);
					res.push_back(temp);
					temp.clear();
				}
			}
			if (y >= 1)
			{
				if (board[x][y - 1] == c)
				{
					temp.push_back(x);
					temp.push_back(y - 1);
					res.push_back(temp);
					temp.clear();
				}
			}
			if (x < rows - 1)
			{
				if (board[x + 1][y] == c)
				{
					temp.push_back(x + 1);
					temp.push_back(y);
					res.push_back(temp);
					temp.clear();
				}
			}
			if (y < columns - 1)
			{
				if (board[x][y + 1] == c)
				{
					temp.push_back(x);
					temp.push_back(y + 1);
					res.push_back(temp);
					temp.clear();
				}
			}
		}
		return res;
    }
    
    void setpass(vector<vector<bool>>& p, int rows, int columns)
    {
        vector<bool> temp;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                temp.push_back(false);
            }
            p.push_back(temp);
            temp.clear();
        }
    }
    vector<vector<bool>> passed;
};