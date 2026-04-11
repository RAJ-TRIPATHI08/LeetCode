class Solution {
    int n;
    int[][] dp;
    int[] cost;
    int[] nums;

    public int minOperations(int[] nums, int k) {
        n = nums.length;
        this.nums = nums;
        cost = new int[n];
        dp = new int[n][k + 1];

        if (k > n / 2)
            return -1;

        if (k == 0)
            return 0;

        // initialize dp with -1
        for (int[] row : dp)
            Arrays.fill(row, -1);

        for (int i = 0; i < n; i++) {
            int left = (i == 0) ? nums[n - 1] : nums[i - 1];
            int right = (i == n - 1) ? nums[0] : nums[i + 1];

            int req = Math.max(left, right) + 1;
            cost[i] = Math.max(0, req - nums[i]);
        }

        int res1 = solve(0, n - 2, k);

        // reset dp
        for (int[] row : dp)
            Arrays.fill(row, -1);

        int res2 = solve(1, n - 1, k);

        int res = Math.min(res1, res2);

        return (res > 1e9) ? -1 : res;
    }

    int solve(int i, int j, int k) {
        if (k == 0)
            return 0;

        if (i > j)
            return (int)1e9;

        if (dp[i][k] != -1)
            return dp[i][k];

        int notPick = solve(i + 1, j, k);
        int pick = cost[i] + solve(i + 2, j, k - 1);

        return dp[i][k] = Math.min(pick, notPick);
    }
}