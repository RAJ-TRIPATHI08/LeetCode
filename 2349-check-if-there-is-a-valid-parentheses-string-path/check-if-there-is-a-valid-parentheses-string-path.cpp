class Solution {
public:
    int m, n;
    int dp[101][101][205];
    bool solve(vector<vector<char>>& grid, int valid, int i, int j)
    {
        if(i >= m || j >= n)
            return false;

        if(grid[i][j] == '(')
            valid += 1;
        
        if(grid[i][j] == ')')
            valid -= 1;

        if(valid < 0)
            return false;

        if(i == m-1 && j == n-1)
        {
            if(valid == 0)
                return true;

            return false;
        }

        if(dp[i][j][valid] != -1)
            return dp[i][j][valid];
        
        bool right = solve(grid, valid, i, j+1);
        bool down = solve(grid, valid, i+1, j);

        return dp[i][j][valid] = right || down;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, 0);
    }
};