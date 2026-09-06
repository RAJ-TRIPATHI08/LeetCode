class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        function<int(int, int)> solve = [&](int i, int j) {
            if(j == n)
                return 1;

            if(i == m)
                return 0;

            if(dp[i][j] != -1)
                return dp[i][j];

            int pick = 0;

            if(s.at(i) == t.at(j))
                pick = solve(i+1, j+1);

            int notPick = solve(i+1, j);

            return dp[i][j] = pick + notPick;
        };
        return solve(0, 0);
    }
};