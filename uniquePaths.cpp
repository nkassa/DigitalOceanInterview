class Solution {
public:
    vector<vector<int>> memo;
    int uniquePaths(int m, int n) 
    {
        memo = vector(m, vector(n, -1));
        memo[0][0] = 1;
        return dp(m-1, n-1);
    }
    int dp(int m, int n)
    {
        if(memo[m][n] != -1)
        {
            return memo[m][n];
        }
        int way = 0;
        if(m > 0)
        {
            way += memo[m-1][n];
        }
        if(n > 0)
        {
            way += memo[m][n-1];
        }
        memo[m][n] = way;
        return memo[m][n];
    }
};