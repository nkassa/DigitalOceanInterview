class Solution {
public:
    int knightDialer(int n) {
        const int MOD = pow(10,9) + 7;

        // Knight moves mapping from each digit
        vector<vector<int>> moves = {
            {4, 6},    // 0
            {6, 8},    // 1
            {7, 9},    // 2
            {4, 8},    // 3
            {0, 3, 9}, // 4
            {},        // 5 (no moves)
            {0, 1, 7}, // 6
            {2, 6},    // 7
            {1, 3},    // 8
            {2, 4}     // 9
        };

        // dp[d] = number of sequences ending at digit d
        vector<long long> dp(10, 1); // For length = 1, 1 way for each digit

        for (int step = 2; step <= n; ++step) {
            vector<long long> next(10, 0);
            for (int digit = 0; digit <= 9; ++digit) {
                for (int prev : moves[digit]) {
                    next[digit] = (next[digit] + dp[prev]) % MOD;
                }
            }
            dp.swap(next);
        }

        long long ans = 0;
        for (int digit = 0; digit <= 9; ++digit) {
            ans = (ans + dp[digit]) % MOD;
        }
        return (int)ans;
    }
};