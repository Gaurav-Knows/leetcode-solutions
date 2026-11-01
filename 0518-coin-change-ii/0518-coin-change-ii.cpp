class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {

                long long sum = dp[i] + dp[i - coin];

                dp[i] = min(sum, (long long)INT_MAX);
            }
        }

        return (int)dp[amount];
    }
};