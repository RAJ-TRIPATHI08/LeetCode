class Solution {
public:
    int x; 
    int y;
    int dp[101][101];

    int solve(int i, int j)
    {
        if(i >= x || j >= y)
            return 0;

        if(i == x-1 && j == y-1)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        int right = solve(i, j+1);
        int down = solve(i+1, j);
        return dp[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        x = m;
        y = n;
        memset(dp, -1, sizeof(dp));

        return solve(0, 0);
    }
};