class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> cost;
    vector<int> nums;
    int minOperations(vector<int>& nums, int k) {
        n = nums.size();
        this->nums = nums;
        cost.resize(n);
        dp.resize(n, vector<int>(k+1, -1));

        if(k > n/2)
            return -1;

        if(k == 0)
            return 0;

        for(int i = 0; i < n; i++)
        {   
            int left = (i == 0)? nums[n-1] : nums[i-1];
            int right = (i == n-1)? nums[0] : nums[i+1];

            int req = max(left, right) + 1;
            cost[i] = max(0, req - nums[i]);
        }

        int res1 = solve(0, n-2, k);

        dp.assign(n, vector<int>(k+1, -1));

        int res2 = solve(1, n-1, k);

        int res = min(res1, res2);

        return (res > 1e9)? -1 : res;
    }

    int solve(int i, int j, int k)
    {
        if(k == 0)
            return 0;
            
        if(i > j)
            return 1e9;

        if(dp[i][k] != -1)
            return dp[i][k];
        
        int notPick = solve(i+1, j, k);
        int pick = cost[i] + solve(i+2, j, k-1);

        return dp[i][k] = min(pick, notPick);
    }
};