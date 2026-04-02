class Solution {
public:
    int n;
    int m;

    int dp[101][101];

    int solve(vector<vector<int>>& grid, int i, int j)
    {
        if(i >= n || j >= m)
            return 0;

        if(grid[i][j] == 1)
            return 0;      // obstacle on this path

        if(i == n-1 && j == m-1)
            return 1;     // found a step

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int right = solve(grid, i, j+1);
        int down = solve(grid, i+1, j);
        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(obstacleGrid, 0, 0);
    }
};