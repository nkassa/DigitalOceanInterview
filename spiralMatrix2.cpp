class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        int row = 0;
        int col = 0;
        int maxRow = n-1;
        int maxCol = n-1;
        long long num = 1;
        vector<vector<int>> ans(n, vector(n, 0));
        while(num <= pow(n,2))
        {
            for(int i = col; i <= maxCol; i++)
            {
                ans[row][i] = num;
                num++;
            }
            row++;
            for(int i = row; i <= maxRow; i++)
            {
                ans[i][maxCol] = num;
                num++;
            }
            maxCol--;
            for(int i = maxCol; i >= col; i--)
            {
                ans[maxRow][i] = num;
                num++;
            }
            maxRow--;
            for(int i = maxRow; i >= row; i--)
            {
                ans[i][col] = num;
                num++;
            }
            col--;
        }
        return ans;
    }
};