class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        int dp[201][201];
        memset(dp, 0, sizeof(dp));

        for(int i = m - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(i == m - 1 && j == n - 1)
                {
                    if(dungeon[i][j] > 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = abs(dungeon[i][j]) + 1;
                }
                else
                {
                    int right = (j + 1 < n) ? dp[i][j + 1] : INT_MAX;
                    int down = (i + 1 < m) ? dp[i + 1][j] : INT_MAX;

                    int res = min(right, down) - dungeon[i][j];
                    dp[i][j] = res > 0 ? res : 1;
                }
            }
        }

        return dp[0][0];
    }
};