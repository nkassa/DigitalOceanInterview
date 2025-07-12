class Solution {
public:
    vector<vector<int>> memo;
    int mod = pow(10,9)+7;
    int numRollsToTarget(int n, int k, int target) 
    {
        memo = vector(n+1, vector(target+1, -1));
        memo[0][0] = 1;
        return dp(n, target, k); 
    }
    int dp(int dice, int target, int& k)
    {
        if(memo[dice][target] != -1)
        {
            return memo[dice][target] % mod;
        }
        if(target == 0 || dice == 0)
        {
            return 0;
        }
        long int way = 0;
        for(int i = 1; i <= k; i++)
        {
            if(dice > 0 && target-i >= 0)
            {
                way = (way + dp(dice-1, target-i, k)) % mod;
            }
        }
        memo[dice][target] = way;
        return memo[dice][target];
    }
};