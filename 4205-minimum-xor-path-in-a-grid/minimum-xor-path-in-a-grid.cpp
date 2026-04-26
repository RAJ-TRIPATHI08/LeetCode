class Solution {
public:
    int m, n;
    vector<vector<vector<int>>>dp;

    int solve(vector<vector<int>>& grid, int i, int j, int x)
    {
        if(i >= m || j >= n)
            return INT_MAX;
            
        x = x ^ grid[i][j];
        if(i == m-1 && j == n-1)
            return x;

        if(dp[i][j][x] != -1)
            return dp[i][j][x];

        int right = solve(grid, i, j+1, x);
        int down = solve(grid, i+1, j, x);

        return dp[i][j][x] = min(right, down);
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m,vector<vector<int>>(n,vector<int>(1024,-1)));

        return solve(grid, 0, 0, 0);
    }
};