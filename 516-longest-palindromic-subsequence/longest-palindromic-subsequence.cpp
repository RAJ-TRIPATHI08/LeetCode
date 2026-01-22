class Solution {
private:
    int dp[1001][1001];
    int solve(string &s1, string &s2, int i, int j)
    {
        if(i >= s1.length() || j >= s2.length())
            return 0;

        if(dp[i][j] != -1) 
            return dp[i][j];

        if(s1[i] == s2[j])
            return dp[i][j] = 1 + solve(s1, s2, i+1, j+1);
        
        return dp[i][j] = max(solve(s1, s2, i+1, j), solve(s1, s2, i, j+1));
    }

    int lcs(string s1, string s2) {
        int m = s1.size(), n = s2.size();

        memset(dp, -1, sizeof(dp));

        return solve(s1, s2, 0, 0);
    }
public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return lcs(s, s2);
    }
};