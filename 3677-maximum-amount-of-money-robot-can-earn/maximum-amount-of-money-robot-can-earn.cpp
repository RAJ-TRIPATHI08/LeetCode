class Solution {
public:
    int n; 
    int m;
    int dp[501][501][3];
    bool vis[501][501][3];
    
    int solve(vector<vector<int>>& coins, int i, int  j, int k)
    {
        if(i == n-1 && j == m-1)
        {
            if(coins[i][j] < 0 && k > 0)
                return 0;
            
            return coins[i][j];
        }

        if(i >= n || j >= m)
        {
            return -1e9;
        }

        if(vis[i][j][k])
            return dp[i][j][k];
        
        
        int pick = coins[i][j] + max(solve(coins, i+1, j, k), solve(coins, i, j+1, k));

        int notPick = -1e9;
        if(k > 0)
        {
            int NotPickRight = solve(coins, i+1, j, k-1);
            int NotPickDown = solve(coins, i, j+1, k-1);
            notPick = max(NotPickRight, NotPickDown);
        }
        
        vis[i][j][k] = true;
        return dp[i][j][k] = max(pick, notPick);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size();
        m = coins[0].size();

        memset(dp, -1, sizeof(dp));
        memset(vis, false, sizeof(vis));

        return solve(coins, 0, 0, 2);
    }
};