class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        for(int c : coins)
        {
            for(int amt = c; amt <= amount; amt++)
            {
                dp[amt] = min(dp[amt], 1 + dp[amt-c]);
            }
        }
        return dp[amount] == INT_MAX-1? -1 : dp[amount];
    }
};