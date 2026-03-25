class Solution {
public:
    int dp[101];
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
        memset(dp, -1, sizeof(dp));

        return solve(nums, 0);
    }
};