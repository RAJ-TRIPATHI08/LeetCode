class Solution {
public:
    int m, n;
    
    int dp[201][201];
    int solve(int i, int j, vector<vector<int>>& g)
    {
        if(i >= m || j >= n)
            return INT_MAX;
        
        if(i == m - 1 && j == n - 1)
        {
            if(g[i][j] > 0)
                return 1;
            return abs(g[i][j]) + 1;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        int right = solve(i, j + 1, g);
        int down = solve(i + 1, j, g);

        int res = min(right, down) - g[i][j];
        return dp[i][j] = res > 0? res : 1;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        m = dungeon.size();
        n = dungeon[0].size();
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, dungeon);
    }
};