class Solution {
public:

    class SegmentTree {
    public:
        vector<int> tree;
        int n;

        SegmentTree(int n) {
            this->n = n;
            tree.resize(4 * n, 0);
        }

        void update(int node, int l, int r, int idx) {

            if(l == r) {
                tree[node]++;
                return;
            }

            int mid = (l + r) / 2;

            if(idx <= mid)
                update(2 * node, l, mid, idx);
            else
                update(2 * node + 1, mid + 1, r, idx);

            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }

        int query(int node, int l, int r, int ql, int qr) {

            if(ql > r || qr < l)
                return 0;

            if(ql <= l && r <= qr)
                return tree[node];

            int mid = (l + r) / 2;

            return query(2 * node, l, mid, ql, qr) +
                   query(2 * node + 1, mid + 1, r, ql, qr);
        }
    };

    vector<int> resultArray(vector<int>& nums) {

        int n = nums.size();

        // coordinate compression
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        unordered_map<int,int> mp;

        int idx = 0;

        for(int x : sorted)
        {
            if(!mp.count(x))
                mp[x] = idx++;
        }

        SegmentTree seg1(idx);
        SegmentTree seg2(idx);

        vector<int> a, b;

        a.push_back(nums[0]);
        b.push_back(nums[1]);

        seg1.update(1, 0, idx - 1, mp[nums[0]]);
        seg2.update(1, 0, idx - 1, mp[nums[1]]);

        for(int i = 2; i < n; i++)
        {
            int pos = mp[nums[i]];

            int greaterA =
                a.size() -
                seg1.query(1, 0, idx - 1, 0, pos);

            int greaterB =
                b.size() -
                seg2.query(1, 0, idx - 1, 0, pos);

            if(greaterA > greaterB)
            {
                a.push_back(nums[i]);
                seg1.update(1, 0, idx - 1, pos);
            }
            else if(greaterA < greaterB)
            {
                b.push_back(nums[i]);
                seg2.update(1, 0, idx - 1, pos);
            }
            else
            {
                if(a.size() <= b.size())
                {
                    a.push_back(nums[i]);
                    seg1.update(1, 0, idx - 1, pos);
                }
                else
                {
                    b.push_back(nums[i]);
                    seg2.update(1, 0, idx - 1, pos);
                }
            }
        }

        vector<int> res = a;

        res.insert(res.end(), b.begin(), b.end());

        return res;
    }
};