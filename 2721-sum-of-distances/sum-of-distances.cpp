class Solution {
public:
    typedef long long ll;

    vector<ll> distance(vector<int>& nums) {
        int n = nums.size();
        vector<ll> res(n, 0);

        unordered_map<int, ll> count, sum;

        // LEFT contribution
        for(int i = 0; i < n; i++) {
            int val = nums[i];

            res[i] += (ll)i * count[val] - sum[val];

            count[val]++;
            sum[val] += i;
        }

        count.clear();
        sum.clear();

        // RIGHT contribution
        for(int i = n - 1; i >= 0; i--) {
            int val = nums[i];

            res[i] += sum[val] - (ll)i * count[val];

            count[val]++;
            sum[val] += i;
        }

        return res;
    }
};