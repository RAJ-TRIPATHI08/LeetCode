class Solution {
public:
    using ll = long long;
    int dieSimulator(int n, vector<int>& rollMax) {
        int dp[5001][7][16];
        memset(dp, -1, sizeof(dp));
        int mod = 1e9+7;
        function<int(int, int, int)> solve = [&](int n, int last, int k) {
            if(n == 0)
                return 1;
            if(dp[n][last][k] != -1)
                return dp[n][last][k];
            ll res = 0;
            for(int i = 1; i <= 6; i++)
            {
                if(i == last)
                {
                    if(k < rollMax[i-1])
                        res += solve(n-1, i, k+1);
                }
                else 
                    res += solve(n-1, i, 1);
                res %= mod;
            }
            return dp[n][last][k] = (int)res;
        };
        return solve(n, 0, 0);
    }
};