class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> res;
        string temp;
        int rows = board.size();
        if(rows == 0)
            return res;
        int columns = board[0].size();
        if(columns == 0)
            return res;
        setpass(passed, rows, columns);
        find(board, root, res, -1, -1, temp);
        
        vector<string> vec;
        sort(res.begin(), res.end());
        if(res.size() != 0)
            vec.push_back(res[0]);
        for(int i = 1; i < res.size(); i++)
        {
            if(res[i] != res[i-1])
                vec.push_back(res[i]);
        }
        return vec;
    }
    
    struct TrieNode
    {
        TrieNode* next[26];
        bool leaf;
        bool isword;
        TrieNode()
        {
            leaf = true;
            isword = false;
            for(int i = 0; i < 26; i++)
                next[i] = NULL;
        }
    };
    
    TrieNode* buildTrie(vector<string>& words)
    {
        TrieNode* res = new TrieNode();
        TrieNode* temp = NULL;
        for(int i = 0; i < words.size(); i++)
        {
            temp = res;
            for(int j = 0; j < words[i].length(); j++)
            {
                if(temp->next[words[i][j] - 97] == NULL)
                {
                    temp->leaf = false;
                    temp->next[words[i][j] - 97] = new TrieNode();
                }
                temp = temp->next[words[i][j] - 97];
            }
            temp->isword = true;
        }
        return res;
    }
    
    void find(vector<vector<char>>& board, TrieNode* words, vector<string>& res, int lastx, int lasty, string temp)
    {
        if(words->leaf == true)
        {
            if(temp.length() != 0)
                res.push_back(temp);
        }
        else
        {
            if(words->isword == true)
            {
                if(temp.length() != 0)
                    res.push_back(temp);
            }
            for(int i = 0; i < 26; i++)
            {
                if(words->next[i] != NULL)
                {
                    vector<vector<int>> bingle = findchar(board, (char)(i+97), lastx, lasty);
                    for(int j = 0; j < bingle.size(); j++)
                    {
                        if(passed[bingle[j][0]][bingle[j][1]])
                            continue;
                        passed[bingle[j][0]][bingle[j][1]] = true;
                        find(board, (words->next)[i], res, bingle[j][0], bingle[j][1], temp+(char)(i+97));
                        passed[bingle[j][0]][bingle[j][1]] = false;
                    }
                }
            }
        }
    }
    
    vector<vector<int>> findchar(vector<vector<char>>& board, char c, int x, int y)
    {
        int rows = board.size();
        int columns = board[0].size();
        vector<vector<int>> res;
        vector<int> temp;
        if(x == -1 && y == -1)
        {
            for(int i = 0; i < board.size(); i++)
            {
                for(int j = 0; j < board[0].size(); j++)
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