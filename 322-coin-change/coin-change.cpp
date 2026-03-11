class Solution {
public:
    int dp[12 + 1][10000 + 1];

    int solve(vector<int> & coins, int curr, int amt)
    {
        if(curr >= coins.size() || amt <= 0)
            return (amt == 0)? 0 : INT_MAX - 1;

        int res = -1;

        if (dp[curr][amt] != -1)
            return dp[curr][amt];

        if(coins[curr] > amt)
        {
            // not pick
            int notPick = 0 + solve(coins, curr + 1, amt);
            dp[curr][amt] = res = notPick;
        }
        else
        {
            // pick or not pick case
            int pick = 1 + solve(coins, curr + 0, amt - coins[curr]);
            int notPick = 0 + solve(coins, curr + 1, amt);
            dp[curr][amt] = res = min(pick, notPick);
        }
        return dp[curr][amt] = res;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int res = solve(coins, 0, amount);
        return res == INT_MAX - 1? -1:res;
    }
};