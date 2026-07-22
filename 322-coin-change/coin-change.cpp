class Solution {
public:
    int dp[13][10001];
    int solve(vector<int>& a, int idx, int amt)
    {
        if(idx >= a.size() || amt <= 0)
            return (amt == 0)? 0:INT_MAX-1;

        if(dp[idx][amt] != -1)
            return dp[idx][amt];

        int res = -1;
        if(a[idx] > amt)
        {
            int notPick = 0 + solve(a, idx+1, amt);
            res = notPick;
            dp[idx][amt] = res;
        }
        else
        {
            int pick = 1 + solve(a, idx, amt-a[idx]);
            int notPick = 0 + solve(a, idx+1, amt);
            res = min(pick, notPick);
            dp[idx][amt] = res;
        }
        return dp[idx][amt] = res;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int res = solve(coins, 0, amount);
        return (res == INT_MAX-1)? -1 : res;
    }
};