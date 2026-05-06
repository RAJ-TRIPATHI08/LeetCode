class Solution {
public:
    typedef long long ll;
    // Count trailing zeros in n!
    ll f(ll x) {
        ll trailingZeroes = 0;
        while (x > 0) {
            x /= 5;
            trailingZeroes += x;
        }
        return trailingZeroes;
    }

    // Find smallest n such that f(n) >= k
    ll findFirst(ll k) {
        ll low = 0, high = 5LL * (k + 1);

        while (low < high) {
            ll mid = low + (high - low) / 2;
            if (f(mid) < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    int preimageSizeFZF(int k) {
        ll first = findFirst(k);

        if (f(first) != k)
            return 0;   // no such n exists

        return 5;       // always 5 if exists
    }
};