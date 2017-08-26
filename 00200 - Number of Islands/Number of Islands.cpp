class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows == 0)
            return 0;
        int columns = grid[0].size();
        if(columns == 0)
            return 0;
        
        int len = rows*columns;
        vector<int> rec(len);
        for(int i = 0; i < len; i++)
            rec[i] = i;
        for(int i = 0; i < len; i++)
        {
            int x = i/columns;
            int y = i%columns;
            if(x < rows - 1)
            {
                if(grid[x][y] == grid[x+1][y])
                    unions(rec, i, i + columns);
            }
            if(y < columns - 1)
            {
                if(grid[x][y] == grid[x][y+1])
                    unions(rec, i, i + 1);
            }
        }
        
        set<int> ss;
        for(int i = 0; i < len; i++)
        {
            int r = find(rec, i);
            if(grid[r/columns][r%columns] == '1')
                ss.insert(find(rec, i));
        }
        return ss.size();
    }
    
    void unions(vector<int>& record, int m, int n)
    {
        int rootm = find(record, m);
        int rootn = find(record, n);
        if(rootm != rootn)
        {
            record[rootn] = record[rootm];
        }
        while(record[n] != record[rootm])
        {
            int temp = record[n];
            record[n] = record[m];
            n = temp;
        }
    }
    
    int find(vector<int>& record, int x)
    {
        while(x != record[x])
        {
            record[x] = record[record[x]];
            x = record[x];
        }
        return x;
    }
};