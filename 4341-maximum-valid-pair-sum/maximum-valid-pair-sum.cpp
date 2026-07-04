class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int res = INT_MIN;
        vector<int> pref(n, 0);
        vector<int> suff(n, 0);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = max(pref[i - 1], nums[i]);
        }

        suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = max(suff[i + 1], nums[i]);
        }

        for (int i = 0; i + k < n; i++) {
            res = max(res, pref[i] + suff[i + k]);
        }

        return res;
    }
};