class Solution {
public:
    int n;
    int m;
    int dp[201][201];
    int solve(vector<vector<int>>& grid, int i, int j)
    {
        if(i >= n || j >= m)
            return 1e9;

        if(i == n-1 && j == m-1)
            return grid[i][j];

        if(dp[i][j] != -1)
            return dp[i][j];

        int right = solve(grid, i, j+1);
        int down = solve(grid, i+1, j);

        return dp[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();    
        m = grid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(grid, 0, 0);    
    }
};