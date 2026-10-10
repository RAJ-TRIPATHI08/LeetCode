class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        unordered_map<int, int> freq;
        long long total = 0;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            if (d > 0) {
                freq[d]++;
                total += d;
                mx = max(mx, d);
            }
        }

        // Can make everything zero
        if (total <= k) return 0;

        // Max-heap of (value, frequency)
        priority_queue<pair<int, int>> pq;
        for (auto& [val, f] : freq) {
            pq.emplace(val, f);
        }

        while (k > 0 && !pq.empty()) {
            auto [val, f] = pq.top();
            pq.pop();

            // How many we can decrease in this batch
            int take = min((long long)f, k);
            k -= take;

            // Remaining ones stay at 'val'
            if (f > take) {
                pq.emplace(val, f - take);
            }

            // The ones we decreased go to val-1
            if (val > 1) {
                // Merge with existing (val-1) if present
                if (!pq.empty() && pq.top().first == val - 1) {
                    auto [v2, f2] = pq.top();
                    pq.pop();
                    pq.emplace(v2, f2 + take);
                } else {
                    pq.emplace(val - 1, take);
                }
            }
            // if val == 1, the decreased ones become 0 → just discard them
        }

        long long res = 0;
        while (!pq.empty()) {
            auto [val, f] = pq.top();
            pq.pop();
            res += (long long)val * val * f;
        }
        return res;
    }
};