class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> memo(amount+1, amount+1);
        memo[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < coins.size(); j++)
            {
                if(i - coins[j] >= 0)
                {
                    memo[i] = min(memo[i], memo[i-coins[j]] + 1);
                }
            }
        }
        if(memo[amount] == amount+1)
        {
            return -1;
        }
        return memo[amount];
    }
};