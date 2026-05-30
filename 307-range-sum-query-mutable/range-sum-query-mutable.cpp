class NumArray {
public:
    vector<int> seg;
    vector<int> nums;
    int n;

    NumArray(vector<int>& nums) {
        this->n = nums.size();
        this->nums = nums;

        seg.assign(4 * n, 0);
        segTree(0, 0, n - 1);
    }

    void segTree(int node, int l, int r) {
        if (l == r) {
            seg[node] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        segTree(2 * node + 1, l, mid);
        segTree(2 * node + 2, mid + 1, r);

        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    void update(int idx, int val, int node, int l, int r) {
        if (l == r) {
            seg[node] = val;
            nums[idx] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
            update(idx, val, 2 * node + 1, l, mid);
        else
            update(idx, val, 2 * node + 2, mid + 1, r);

        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    void update(int index, int val) {
        update(index, val, 0, 0, n - 1);
    }

    int query(int ql, int qr, int node, int l, int r) {
        if (r < ql || l > qr)
            return 0;

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = l + (r - l) / 2;

        return query(ql, qr, 2 * node + 1, l, mid) +
               query(ql, qr, 2 * node + 2, mid + 1, r);
    }

    int sumRange(int left, int right) {
        return query(left, right, 0, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index, val);
 * int param_2 = obj->sumRange(left, right);
 */