class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<bool>> seen;
    vector<vector<int>> image;
    int color;
    int num;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        m = image.size();
        n = image[0].size();
        this->image = image;
        this->color = color;
        seen = vector(m, vector<bool>(n, false));
        seen[sr][sc] = true;
        num = image[sr][sc];
        image[sr][sc] = color;
        dfs(sr, sc, image);
        return image;
    }
    void dfs(int row, int col, vector<vector<int>>& image)
    {
        for(vector<int> direction: directions)
        {
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];
            if(valid(nextRow, nextCol) && !seen[nextRow][nextCol])
            {
                seen[nextRow][nextCol] = true;
                image[nextRow][nextCol] = color;
                dfs(nextRow, nextCol, image);
            }
        }
    }
    bool valid(int row, int col)
    {
        return 0 <= row && row < m && 0 <= col && col < n && image[row][col] == num;
    }
};