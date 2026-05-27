class Solution {
public:
    static const int MAXV = 100000 + 5;
    int seg[4 * MAXV];

    void update(int idx, int val, int node, int l, int r) {
        if (l == r) {
            seg[node] = max(seg[node], val);
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid)
            update(idx, val, 2 * node, l, mid);
        else
            update(idx, val, 2 * node + 1, mid + 1, r);

        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }

    int query(int ql, int qr, int node, int l, int r) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return seg[node];

        int mid = (l + r) / 2;
        return max(
            query(ql, qr, 2 * node, l, mid),
            query(ql, qr, 2 * node + 1, mid + 1, r)
        );
    }

    int lengthOfLIS(vector<int>& nums, int k) {
        memset(seg, 0, sizeof(seg));

        int ans = 1;

        for (int x : nums) {
            int L = max(1, x - k);
            int R = x - 1;

            int best = (L <= R) ? query(L, R, 1, 1, MAXV) : 0;
            int cur = best + 1;

            update(x, cur, 1, 1, MAXV);

            ans = max(ans, cur);
        }

        return ans;
    }
};