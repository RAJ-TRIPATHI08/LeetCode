class Solution {
public:
    typedef long long ll;
    ll maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<ll> dpW(n + 1, 0), dpWo(n + 1, 0);
        vector<ll> ndpW(n + 1, 0), ndpWo(n + 1, 0);
        vector<ll> cSum(n + 1, 0), ncSum(n + 1, 0);

        // Initialize cSum for first column
        for (int i = 0; i < n; i++) {
            cSum[i + 1] = cSum[i] + (ll)grid[i][0];
        }

        ll dpWm = 0;

        for (int j = 1; j < n; j++) {
            ll ndpWm = 0;

            // Build prefix sum for current column
            for (int i = 0; i < n; i++) {
                ncSum[i + 1] = ncSum[i] + (ll)grid[i][j];
            }

            for (int i = 0; i <= n; i++) {
                ll woA = dpWm;
                ll wA = 0;

                // First part: k in [0, i]
                for (int k = 0; k <= i; k++) {
                    ll x = dpWo[k] + (cSum[i] - cSum[k]);
                    wA = max(wA, x);
                    woA = max(woA, x);
                }

                // Second part: k in [i+1, n]
                for (int k = i + 1; k <= n; k++) {
                    ll x = dpW[k] + (ncSum[k] - ncSum[i]);
                    wA = max(wA, x);
                }

                ndpW[i] = wA;
                ndpWo[i] = woA;
                ndpWm = max(ndpWm, wA);
            }

            // Copy ndp → dp
            dpW = ndpW;
            dpWo = ndpWo;
            cSum = ncSum;

            dpWm = ndpWm;
        }

        return *max_element(dpW.begin(), dpW.end());
    }
};