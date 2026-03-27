class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];

        vector<int> dp(n+1, 0);

        dp[0] = 0;

        // case1: if we take first house
        for(int i = 1; i <= n - 1; i++)
        {
            int skip = dp[i-1];
            int take = nums[i-1] + ((i-2 >= 0)? dp[i-2] : 0);

            dp[i] = max(skip, take);
        }

        int res1 = dp[n-1];
        dp.clear();

        // case2: if we do not take first house
        dp[0] = 0;
        dp[1] = 0;

        
        for(int i = 2; i <= n; i++)
        {
            int skip = dp[i-1];
            int take = nums[i-1] + ((i-2 >= 0)? dp[i-2] : 0);

            dp[i] = max(skip, take);
        }

        int res2 = dp[n];
        return max(res1, res2);
    }
};