class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int m;
    int n;
    vector<vector<bool>> seen;
    vector<vector<int>> grid;
    int numEnclaves(vector<vector<int>>& grid) 
    {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        seen = vector(m, vector<bool>(n, false));
        for(int i = 0; i < n; i++)
        {
            if(!seen[0][i] && grid[0][i] == 1)
            {
                seen[0][i] = true;
                dfs(0, i);
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(!seen[m-1][i] && grid[m-1][i] == 1)
            {
                seen[m-1][i] = true;
                dfs(m-1, i);
            }
        }
        for(int i = 0; i < m; i++)
        {
            if(!seen[i][0] && grid[i][0] == 1)
            {
                seen[i][0] = true;
                dfs(i, 0);
            }
        }
        for(int i = 0; i < m; i++)
        {
            if(!seen[i][n-1] && grid[i][n-1] == 1)
            {
                seen[i][n-1] = true;
                dfs(i, n-1);
            }
        }
        int ans = 0;
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(!seen[row][col] && grid[row][col] == 1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(int row, int col)
    {
        for(vector<int> direction: directions)
        {
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];
            if(valid(nextRow, nextCol) && !seen[nextRow][nextCol])
            {
                seen[nextRow][nextCol] = true;
                dfs(nextRow, nextCol);
            }
        }
    }
    bool valid(int row, int col)
    {
        return row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1;
    }
};