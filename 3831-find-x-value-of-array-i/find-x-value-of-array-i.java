class Solution {
    public long[] resultArray(int[] nums, int k) {
        long[] res = new long[k];
        long[] dp = new long[k];

        for(int n : nums)
        {
            int val = n % k;    
            long[] new_dp = new long[k];

            new_dp[val] = 1;

            for(int prev = 0; prev < k; prev++)
            {
                if(dp[prev] == 0)
                    continue;

                int new_rem = (int)(val * prev * 1L) % k;
                new_dp[new_rem] += dp[prev];
            }

            for(int r = 0; r < k; r++)
            {
                res[r] += new_dp[r];
            }
            dp = new_dp;
        }
        
        return res;
    }
}