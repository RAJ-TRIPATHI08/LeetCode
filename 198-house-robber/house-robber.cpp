class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int idx)
    {
        if(idx >= nums.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int pick = nums[idx] + solve(nums, idx + 2);
        int notpick = solve(nums, idx + 1);
        return dp[idx] = max(pick, notpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);

        return solve(nums, 0);
    }
};