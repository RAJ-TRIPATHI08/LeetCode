class SegTree {
public:
    int n;
    vector<int> seg;

    SegTree(int sz) {
        n = sz;
        seg.assign(4 * n, 0);
    }

    void update(int idx, int val, int node, int l, int r) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(idx, val, 2 * node + 1, l, mid);
        else
            update(idx, val, 2 * node + 2, mid + 1, r);

        seg[node] = max(seg[2 * node + 1], seg[2 * node + 2]);
    }

    void update(int idx, int val) {
        update(idx, val, 0, 0, n - 1);
    }

    int query(int ql, int qr, int node, int l, int r) {
        if (r < ql || l > qr)
            return 0;

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        return max(
            query(ql, qr, 2 * node + 1, l, mid),
            query(ql, qr, 2 * node + 2, mid + 1, r)
        );
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(l, r, 0, 0, n - 1);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        vector<int> coords = {0};

        for (auto &q : queries) {
            coords.push_back(q[1]);
        }

        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());

        int m = coords.size();

        unordered_map<int, int> mp;
        for (int i = 0; i < m; i++)
            mp[coords[i]] = i;

        SegTree st(m);

        set<int> obs;
        obs.insert(0);

        vector<bool> ans;

        for (auto &q : queries) {

            if (q[0] == 1) {

                int p = q[1];

                auto itNext = obs.lower_bound(p);
                auto itPrev = prev(itNext);

                int prv = *itPrev;
                int nxt = (itNext == obs.end() ? -1 : *itNext);

                obs.insert(p);

                st.update(mp[p], p - prv);

                if (nxt != -1) {
                    st.update(mp[nxt], nxt - p);
                }
            }
            else {

                int x = q[1];
                int sz = q[2];

                auto it = obs.upper_bound(x);

                int lastObs = 0;

                if (it != obs.begin()) {
                    --it;
                    lastObs = *it;
                }

                int idx = mp[lastObs];

                int mxGap = st.query(0, idx);

                mxGap = max(mxGap, x - lastObs);

                ans.push_back(mxGap >= sz);
            }
        }

        return ans;
    }
};