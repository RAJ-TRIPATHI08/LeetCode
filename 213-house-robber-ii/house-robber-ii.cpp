class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums, int i, int j)
    {
        if(i > j)
            return 0;

        if(dp[i] != -1)
            return dp[i];
        
        int pick = nums[i] + solve(nums, i+2, j);
        int notpick = solve(nums, i+1, j);
        
        return dp[i] = max(pick, notpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];
    
        if(n == 2)
            return max(nums[0], nums[1]);

        memset(dp, -1, sizeof(dp));

        int take0thIdx = solve(nums, 0, n - 2);

        memset(dp, -1, sizeof(dp));

        int take1stIdx = solve(nums, 1, n - 1);
 
        return max(take0thIdx, take1stIdx);
    }
};