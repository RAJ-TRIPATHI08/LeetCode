class Solution {
public:
    int t[1001][1001];
    int solve(vector<vector<int>>& a, int p, int idx)
    {
        if(idx >= a.size())
            return 0;

        if(t[p+1][idx] != -1)
            return t[p+1][idx];

        int pick = 0;

        if(p == -1 || a[p][1] < a[idx][0])
            pick = 1 + solve(a, idx, idx + 1);

        int notPick = solve(a, p, idx + 1);
        return t[p+1][idx] = max(pick, notPick);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        memset(t, -1, sizeof(t));
        sort(begin(pairs), end(pairs));

        return solve(pairs, -1, 0);
    }
};