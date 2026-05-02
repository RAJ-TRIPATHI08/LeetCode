class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq; // stores indices
        vector<int> dp(n);

        dp[0] = nums[0];
        dq.push_back(0);

        int res = dp[0];

        for (int i = 1; i < n; i++) 
        {
            // remove out of window
            while (!dq.empty() && dq.front() < i - k)
                dq.pop_front();

            dp[i] = nums[i] + max(0, dp[dq.front()]);

            // maintain decreasing dp
            while (!dq.empty() && dp[dq.back()] <= dp[i])
                dq.pop_back();

            dq.push_back(i);

            res = max(res, dp[i]);
        }

        return res;
    }
};