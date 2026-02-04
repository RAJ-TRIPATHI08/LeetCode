class Solution {
public:
    typedef long long ll;
    int n;
    vector<vector<ll>> dp;

    ll solve(int i, int trend, vector<int>& nums)
    {
        if(i >= n)
        {
            if(trend == 3)
            {
                return 0;       // out of bound case, and no more elements there
            }
            else
            {
                return LLONG_MIN/2;     // we never found trend 3 
            }
        }

        if(dp[i][trend] != LLONG_MIN)
            return dp[i][trend];

        ll take = LLONG_MIN/2;
        ll skip = LLONG_MIN/2;

        if(trend == 0)
        {
            skip = solve(i+1, 0, nums);
        }

        if(i+1 < n)
        {
            int curr = nums[i];
            int next = nums[i+1];

            if(trend == 0 && next > curr)
            {
                take = max(take, curr + solve(i+1, 1, nums));
            }
            else if(trend == 1)    // start a trend
            {
                if(next > curr)    // trend 1 started
                {
                    take = max(take, curr + solve(i+1, 1, nums));
                }
                else if(next < curr)    // dec trend 2 started
                {
                    take = max(take, curr + solve(i+1, 2, nums));
                }
            }
            else if(trend == 2)         // start 3 trend last inc trend
            {
                if(next < curr)
                {
                    take = max(take, curr + solve(i+1, 2, nums));
                }
                else if(next > curr)     // trend 3 started
                {
                    take = max(take, curr + solve(i+1, 3, nums));
                }
            }
            else if(trend == 3 && next > curr)
            {
                take = max(take, curr + solve(i+1, 3, nums));
            }
        }

        if(trend == 3)
        {
            take = max(take, (ll)nums[i]);
        }

        return dp[i][trend] = max(skip, take);
    }

    ll maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        dp.resize(n+1, vector<ll>(4, LLONG_MIN));
        return solve(0, 0, nums);
    }
};
