class Solution {
public:
    using ll = long long;
    struct Node {
        ll ways;
        ll wave;
        Node(ll w = 0, ll wa = 0) {
            ways = w;
            wave = wa;
        }
    };

    string s;
    Node dp[20][11][11][2];
    bool vis[20][11][11][2];

    Node dfs(int pos, int prev2, int prev1, bool started, bool tight) {

        if (pos == s.size())
            return Node(1, 0);

        if (!tight && vis[pos][prev2][prev1][started])
            return dp[pos][prev2][prev1][started];

        int limit = tight ? s[pos] - '0' : 9;

        Node res;

        for (int d = 0; d <= limit; d++) {

            bool ntight = tight && (d == limit);

            // Still leading zeros
            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, 10, 10, 0, ntight);
                res.ways += nxt.ways;
                res.wave += nxt.wave;
            }
            // First non-zero digit
            else if (!started) {
                Node nxt = dfs(pos + 1, 10, d, 1, ntight);
                res.ways += nxt.ways;
                res.wave += nxt.wave;
            }
            // Already started
            else {

                ll add = 0;

                if (prev2 != 10) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d))
                        add = 1;
                }

                Node nxt = dfs(pos + 1, prev1, d, 1, ntight);

                res.ways += nxt.ways;
                res.wave += nxt.wave + add * nxt.ways;
            }
        }

        if (!tight) {
            vis[pos][prev2][prev1][started] = true;
            dp[pos][prev2][prev1][started] = res;
        }

        return res;
    }

    ll solve(ll x) {
        if (x <= 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, 0, 1).wave;
    }

    ll totalWaviness(ll num1, ll num2) {
        return solve(num2) - solve(num1 - 1);
    }
};