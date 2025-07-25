class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> mat;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        this->mat = mat;
        m = mat.size();
        n = mat[0].size();
        queue<vector<int>> queue;
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(mat[row][col] == 0)
                {
                    queue.push({row,col,0});
                }
                else
                {
                    mat[row][col] = INT_MAX;
                }
            }
        }
        while(!queue.empty())
        {
            int r = queue.front()[0];
            int c = queue.front()[1];
            int step = queue.front()[2];
            queue.pop();
            for(vector<int> direction: directions)
            {
                int nextRow = r + direction[0];
                int nextCol = c + direction[1];
                int nextStep = step + 1;
                if(valid(nextRow, nextCol) && mat[nextRow][nextCol] > nextStep)
                {
                    mat[nextRow][nextCol] = nextStep;
                    queue.push({nextRow, nextCol, nextStep});
                }
            }
        }
        return mat;
    }
    bool valid(int row, int col)
    {
        return row >= 0 && row < m && col >= 0 && col < n; 
    }
};