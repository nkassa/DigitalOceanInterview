class Solution {
public:
    vector<int> memo;
    int climbStairs(int n) 
    {
        if(n <= 3)
        {
            return n;
        }
        memo = vector<int>(n+1, -1);
        memo[1] = 1;
        memo[2] = 2;
        return dp(n);
    }
    int dp(int i)
    {
        if(memo[i] != -1)
        {
            return memo[i];
        }
        memo[i] = dp(i-1) + dp(i-2);
        return memo[i];
    }
};
//rec