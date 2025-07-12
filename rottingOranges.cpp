class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<bool>> seen;
    vector<vector<int>> grid;
    int m;
    int n;
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int ans = 0;
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        seen = vector(m, vector<bool>(n, false));
        queue<vector<int>> queue;
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(grid[row][col] == 2)
                {
                    seen[row][col] = true;
                    queue.push({row,col,0});
                }
            }
        }
        while(!queue.empty())
        {
            vector<int> curr = queue.front();
            queue.pop();
            ans = max(ans, curr[2]);
            for(vector<int> direction: directions)
            {
                int nextRow = direction[0] + curr[0];
                int nextCol = direction[1] + curr[1];
                if(valid(nextRow, nextCol) && !seen[nextRow][nextCol])
                {
                    seen[nextRow][nextCol] = true;
                    queue.push({nextRow,nextCol,curr[2]+1});
                }
            }
        }
        return ans;
    }
    bool valid(int row, int col)
    {
        return row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1;
    }
};