class Solution {
public:
    int dp[1001][1001];
    bool isPredecessor(string &a, string &b) {
        if (b.size() != a.size() + 1)
            return false;

        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                j++;  
            }
        }

        return i == a.size();
    }

    int solve(vector<string>& a, int idx, int prev)
    {
        if(idx >= a.size())
            return 0;

        if(dp[prev+1][idx] != -1)
            return dp[prev+1][idx];

        int pick = 0;

        if(prev == -1 || isPredecessor(a[prev], a[idx]))
            pick = 1 + solve(a, idx + 1, idx);

        int notPick = solve(a, idx + 1, prev);

        return dp[prev+1][idx] = max(pick, notPick);
    }

    int longestStrChain(vector<string>& words) {
        memset(dp, -1, sizeof(dp));
        sort(words.begin(), words.end(),
        [](string &x, string &y) {
            return x.size() < y.size();
        });

        return solve(words, 0, -1);
    }
};