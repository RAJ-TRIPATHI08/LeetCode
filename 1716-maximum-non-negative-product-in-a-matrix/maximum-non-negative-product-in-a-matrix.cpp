class Solution {
public:
    typedef long long ll; 
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const ll MOD = 1e9 + 7;

        vector<vector<ll>> mx(m, vector<ll>(n, 0));
        vector<vector<ll>> mn(m, vector<ll>(n, 0));

        mx[0][0] = mn[0][0] = grid[0][0];

        // first row
        for (int j = 1; j < n; j++) {
            mx[0][j] = mn[0][j] = mx[0][j - 1] * grid[0][j];
        }

        // first column
        for (int i = 1; i < m; i++) {
            mx[i][0] = mn[i][0] = mx[i - 1][0] * grid[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                ll x = grid[i][j];

                ll a = mx[i - 1][j] * x;
                ll b = mn[i - 1][j] * x;
                ll c = mx[i][j - 1] * x;
                ll d = mn[i][j - 1] * x;

                mx[i][j] = max({a, b, c, d});
                mn[i][j] = min({a, b, c, d});
            }
        }

        ll ans = mx[m - 1][n - 1];
        if (ans < 0) return -1;
        return ans % MOD;
    }
};