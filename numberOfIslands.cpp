class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<bool>> seen;
    int m;
    int n;
    vector<vector<char>> grid;
    int numIslands(vector<vector<char>>& grid) 
    {
        int ans = 0;
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        seen = vector(m, vector<bool>(n, false));
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(seen[row][col] == false && grid[row][col] == '1')
                {
                    ans++;
                    seen[row][col] = true;
                    dfs(row,col);
                }
            }
        }
        return ans;
    }
    void dfs(int row, int col)
    {
        for(vector<int> direction: directions)
        {
            int nextRow = direction[0] + row;
            int nextCol = direction[1] + col;
            if(valid(nextRow, nextCol) && !seen[nextRow][nextCol])
            {
                seen[nextRow][nextCol] = true;
                dfs(nextRow, nextCol);
            }
        }
    }
    bool valid(int row, int col)
    {
        return row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == '1';
    }
};