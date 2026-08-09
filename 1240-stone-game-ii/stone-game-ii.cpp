class Solution {
public:
    vector<int> piles;
    int n;
    int dp[101][101][2];

    int solve(bool Alice, int i, int M) 
    {
        if (i >= n)
            return 0;

        if(dp[i][M][Alice] != -1)
            return dp[i][M][Alice];

        int stone = 0;
        int res = Alice ? -1 : INT_MAX;

        for (int x = 1; x <= min(2 * M, n - i); x++) 
        {
            stone += piles[i + x - 1];

            if (Alice)
                dp[i][M][Alice] = res = max(res, stone + solve(false, i + x, max(M, x)));
            else
                dp[i][M][Alice] = res = min(res, solve(true, i + x, max(M, x)));
        }

        return dp[i][M][Alice] = res;
    }

    int stoneGameII(vector<int>& piles) {
        this->piles = piles;
        this->n = piles.size();
        memset(dp, -1, sizeof(dp));
        return solve(true, 0, 1);
    }
};