class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        dp[0][0] = 1;//1 comb: no coins for no amount 

        for (int j = 1; j <= coins.size(); j++) {
            for (int i = 0; i <= amount; i++) {
                dp[j][i] = dp[j-1][i]; // Exclude the current coin
            
                if (i >= coins[j-1]) {
                    dp[j][i] += dp[j][i-coins[j-1]];//Include the current coin
                }
            }
        }
        return dp[coins.size()][amount];
    }
};