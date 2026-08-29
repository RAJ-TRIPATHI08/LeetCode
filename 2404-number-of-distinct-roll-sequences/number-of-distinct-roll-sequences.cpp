class Solution {
public:
    int distinctSequences(int n) {
        int mod = 1e9 + 7;
        int dp[n+1][7][7];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, int)> solve = [&] (int idx, int p1, int p2) -> int {
            if(idx == n)
                return 1;
            
            if(dp[idx][p1][p2] != -1)
                return dp[idx][p1][p2];

            int res = 0;
            for(int d = 1; d <= 6; d++)
                if(p1 != d && p2 != d && (p1 == 0 || __gcd(p1, d) == 1))
                    res = (res + solve(idx+1, d, p1)) % mod;
            return dp[idx][p1][p2] = res;
        };
        return solve(0, 0, 0);
    }
};