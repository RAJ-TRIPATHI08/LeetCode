class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[102];

        memset(dp, 0, sizeof(dp));

        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= n; i++)
        {
            int pick = nums[i-1] + dp[i-2];
            int notPick = dp[i-1];

            dp[i] = max(pick, notPick);
        }

        return dp[n];
    }
};