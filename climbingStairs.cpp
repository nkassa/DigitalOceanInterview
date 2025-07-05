class Solution {
public:
    vector<int> memo;
    int climbStairs(int n) 
    {
        if(n <= 3)
        {
            return n;
        }
        memo = vector(n+1, -1);
        memo[1] = 1;
        memo[2] = 2;
        return dp(n);
    }
    int dp(int idx)
    {
        if(memo[idx] != -1)
        {
            return memo[idx];
        }
        memo[idx] = dp(idx-1) + dp(idx-2);
        return memo[idx];
    }
};