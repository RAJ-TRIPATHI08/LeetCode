class Solution {
    static class Pair {
        int first;
        long second;

        Pair(int f, long s) {
            first = f;
            second = s;
        }
    }

    int[] cost;
    int[] nums;
    Pair[] dp;
    int n;

    public long minIncrease(int[] nums) {
        this.nums = nums;

        n = nums.length;
        cost = new int[n];
        dp = new Pair[n];

        for (int i = 1; i < n - 1; i++) {
            int m = Math.max(nums[i - 1], nums[i + 1]);
            if (m < nums[i])
                continue;
            cost[i] = m + 1 - nums[i];
        }

        return solve(1).second;
    }

    Pair solve(int i) {
        if (i >= n - 1)
            return new Pair(0, 0);

        if (dp[i] != null)
            return dp[i];

        Pair skip = solve(i + 1);
        Pair nxt = solve(i + 2);
        Pair take = new Pair(1 + nxt.first, cost[i] + nxt.second);

        Pair res;

        if (skip.first > take.first)
            res = skip;
        else if (take.first > skip.first)
            res = take;
        else
            res = (skip.second > take.second) ? take : skip;

        return dp[i] = res;
    }
}