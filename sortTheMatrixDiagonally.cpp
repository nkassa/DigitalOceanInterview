class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> grid;
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                grid[row-col].push(mat[row][col]);
            }
        }
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                mat[row][col] = grid[row-col].top();
                grid[row-col].pop();
            }
        }
        return mat;
    }
};