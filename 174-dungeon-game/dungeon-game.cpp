class Solution {
public:
    int m, n;

    bool check(int HP, vector<vector<int>>& g)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = HP + g[0][0];

        if(dp[0][0] <= 0)
            return false;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dp[i][j] <= 0)
                    continue;

                if(i + 1 < m)
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + g[i + 1][j]);

                if(j + 1 < n)
                    dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + g[i][j + 1]);
            }
        }

        return dp[m - 1][n - 1] > 0;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        m = dungeon.size();
        n = dungeon[0].size();

        int l = 1, r = 4 * 1e7 + 1;
        int res = r;

        while(l <= r)
        {
            int mid = l + (r - l) / 2;

            if(check(mid, dungeon))
            {
                res = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        return res;
    }
};