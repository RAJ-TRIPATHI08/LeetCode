class Solution {
public:
    vector<vector<int>> dp;
    int n, m;

    int solve(int i, int j, string &s, string &t)
    {
        if(i >= n || j >= m)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == t[j])
            return dp[i][j] = 1 + solve(i+1, j+1, s, t);
        
        return dp[i][j] = max(solve(i+1, j, s, t), solve(i, j+1, s, t));
    }

    int longestCommonSubsequence(string s, string t) {
        this->n = s.size();
        this->m = t.size();

        dp.resize(n+1, vector<int>(m+1, -1));
        return solve(0, 0, s, t);
    }
};