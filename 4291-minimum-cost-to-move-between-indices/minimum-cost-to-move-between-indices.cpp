#define ll long long
class Solution {
public:
        vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<ll> right(n, 0), left(n, 0);

        for (int i = 0; i < n - 1; ++i) {
            if (i == 0 || nums[i] - nums[i - 1] > nums[i + 1] - nums[i]) {
                right[i + 1] = right[i] + 1;
            } else {
                right[i + 1] = right[i] + nums[i + 1] - nums[i];
            }
        }

        for (int i = 1; i < n; ++i) {
            if (i == n - 1 || nums[i] - nums[i - 1] <= nums[i + 1] - nums[i]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = left[i - 1] + nums[i] - nums[i - 1];
            }
        }

        vector<int> res;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            if (l < r) {
                res.push_back(right[r] - right[l]);
            } else {
                res.push_back(left[l] - left[r]);
            }
        }
        return res;
    }
};