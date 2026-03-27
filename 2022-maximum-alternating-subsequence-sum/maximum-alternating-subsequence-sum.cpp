class Solution {
public:
    typedef long long ll;
    ll dp[100000][2];

    ll solve(vector<int>& nums, int idx, bool flag)
    {
        if(idx >= nums.size())
            return 0;

        if(dp[idx][flag] != -1)
            return dp[idx][flag];

        ll skip = solve(nums, idx+1, flag);

        int val = nums[idx];

        if(!flag)
        {
            val = -val;
        }

        ll take = solve(nums, idx+1, !flag) + (ll)val;
        return dp[idx][flag] = max(take, skip);
    }

    ll maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, true);
    }
};