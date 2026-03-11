// class Solution {
// private:
//     int dp[1001][1001];
//     int solve(string &s, int i, int j)
//     {
//         if(i > j) return 0;
        
//         if(dp[i][j] != -1) return dp[i][j];
//         if(i == j) return dp[i][j] = 1;

//         if(s[i] == s[j]) return dp[i][j] = 2 + solve(s, i+1, j-1);

//         return dp[i][j] = max(solve(s, i+1, j), solve(s, i, j-1));
//     }

// public:
//     int longestPalindromeSubseq(string s) {
//         memset(dp, -1, sizeof(dp));
//         return solve(s, 0, s.size()-1);
//     }
// };

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[1001][1001];

        memset(dp, 0, sizeof(dp));

        // base case
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;

        // fill table
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = i+1; j < n; j++)
            {
                if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }

        return dp[0][n-1];
    }
};