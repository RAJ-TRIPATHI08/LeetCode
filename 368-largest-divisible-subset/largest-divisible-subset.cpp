class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));
        vector<int> dp(n, 1);
        vector<int> prev_idx(n, -1);

        int lastIdx = 0;
        int len = 1;

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] % nums[j] == 0)
                {
                    if(dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1; 
                        prev_idx[i] = j;
                    }

                    if(len < dp[i])
                    {
                        len = dp[i];
                        lastIdx = i; 
                    }
                }
            }
        }

        vector<int> res;
        while(lastIdx != -1)
        {
            res.push_back(nums[lastIdx]);
            lastIdx = prev_idx[lastIdx];
        }
        return res;
    }
};