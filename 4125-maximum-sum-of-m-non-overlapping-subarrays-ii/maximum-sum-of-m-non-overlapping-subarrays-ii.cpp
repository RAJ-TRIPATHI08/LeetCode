class Solution {
public:
    using ll = long long;
    const ll NEG = -(ll)1e18;

    struct Node {
        ll val;
        int cnt;
    };

    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();

        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        auto solve = [&](ll penalty) -> pair<ll, int> {
            vector<ll> dpv(n + 1, NEG);
            vector<int> dpc(n + 1, 0);

            dpv[0] = NEG;

            deque<tuple<ll, int, int>> dq;
            // {keyValue, keyCount, index}

            for (int i = 1; i <= n; i++) {

                int j = i - l;

                if (j >= 0) {
                    ll basev;
                    int basec;

                    if (make_pair(dpv[j], dpc[j]) > make_pair(0LL, 0)) {
                        basev = dpv[j];
                        basec = dpc[j];
                    } else {
                        basev = 0;
                        basec = 0;
                    }

                    ll keyv = basev - pref[j];
                    int keyc = basec;

                    while (!dq.empty()) {
                        auto [v, c, idx] = dq.back();
                        if (make_pair(v, c) <= make_pair(keyv, keyc))
                            dq.pop_back();
                        else
                            break;
                    }

                    dq.push_back({keyv, keyc, j});
                }

                while (!dq.empty() && get<2>(dq.front()) < i - r)
                    dq.pop_front();

                ll bestv = dpv[i - 1];
                int bestc = dpc[i - 1];

                if (!dq.empty()) {
                    auto [keyv, keyc, idx] = dq.front();

                    ll candv = keyv + pref[i] - penalty;
                    int candc = keyc + 1;

                    if (make_pair(candv, candc) >
                        make_pair(bestv, bestc)) {
                        bestv = candv;
                        bestc = candc;
                    }
                }

                dpv[i] = bestv;
                dpc[i] = bestc;
            }

            return {dpv[n], dpc[n]};
        };

        ll limit = 0;
        for (int x : nums)
            limit += abs((ll)x);
        limit++;

        ll lo = 0, hi = limit;

        while (lo < hi) {
            ll mid = (lo + hi) / 2;

            auto [val, cnt] = solve(mid);

            if (cnt <= m)
                hi = mid;
            else
                lo = mid + 1;
        }

        ll ans = solve(lo).first + lo * 1LL * m;

        if (lo > 0) {
            ans = min(ans,
                      solve(lo - 1).first + (lo - 1) * 1LL * m);
        }

        return ans;
    }
};