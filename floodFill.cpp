class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<bool>> seen;
    vector<vector<int>> ima;
    int m;
    int n;
    int color;
    int num;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        m = image.size();
        n = image[0].size();
        this->ima = image;
        this->color = color;
        seen = vector(m, vector<bool>(n, false));
        seen[sr][sc] = true;
        num = image[sr][sc];
        ima[sr][sc] = color;
        dfs(sr, sc);
        return ima;
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
                ima[nextRow][nextCol] = color;
                dfs(nextRow, nextCol);
            }
        }
    }
    bool valid(int row, int col)
    {
        return 0 <= row && row < m && 0 <= col && col < n && ima[row][col] == num;
    }
};