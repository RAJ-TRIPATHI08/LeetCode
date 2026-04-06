class Solution {
public:
    int n;
    vector<int> dp;

    int solve(vector<int>& nums, int idx)
    {
        if(idx >= n)
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int move = INT_MAX;

        for(int i = 1; i <= nums[idx]; i++)
        {
            if(idx + i >= n)
                return dp[idx] = 1;

            int next = solve(nums, idx + i);
            if(next != INT_MAX)
                move = min(move, 1 + next);
        }
        return dp[idx] = move;
    }

    int jump(vector<int>& nums) {
        n = nums.size();
        dp.resize(n, -1);
        n = n-1;
        return solve(nums, 0);
    }
};