class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int INF = 1e9;
        int ans = -INF;

        vector<vector<int>> memo(m, vector<int>(n, -1));

        function<int(int, int)> minTo = [&](int i, int j) -> int 
        {
            if (memo[i][j] != -1) return memo[i][j];
            int res = grid[i][j];
            if (i > 0) res = min(res, minTo(i - 1, j));
            if (j > 0) res = min(res, minTo(i, j - 1));
            return memo[i][j] = res;
        };

        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                int mn = INF;
                if (i > 0) mn = min(mn, minTo(i - 1, j));
                if (j > 0) mn = min(mn, minTo(i, j - 1));
                if (mn != INF) 
                    ans = max(ans, grid[i][j] - mn);
            }
        }
        return ans;
    }
};