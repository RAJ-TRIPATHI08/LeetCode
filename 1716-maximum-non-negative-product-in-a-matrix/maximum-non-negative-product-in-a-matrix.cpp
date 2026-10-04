class Solution {
public:
    using ll = long long;
    int m, n, MOD = 1e9+7;
    pair<ll, ll> dp[16][16];

    pair<ll, ll> solve(int i, int j, vector<vector<int>>& grid)
    {
        if(dp[i][j].first != LLONG_MAX)
            return dp[i][j];

        if(i == m-1 && j == n-1)
            return {grid[i][j], grid[i][j]};

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        if(i + 1 < m) 
        {
            auto [downMax, downMin] = solve(i+1, j, grid);  // down
            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});
            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
        }

        if(j + 1 < n)
        {
            auto [rightMax, rightMin] = solve(i, j+1, grid);  // right
            maxVal = max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
            minVal = min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }

        return dp[i][j] = {maxVal, minVal};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        for(int i = 0; i < 16; i++)
        for(int j = 0; j < 16; j++)
            dp[i][j] = {LLONG_MAX, LLONG_MIN};
        
        auto [max, min] = solve(0, 0, grid);    
        return max < 0? -1 : max % MOD;
    }
};