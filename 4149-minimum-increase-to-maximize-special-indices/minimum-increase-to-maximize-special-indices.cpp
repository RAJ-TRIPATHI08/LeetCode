class Solution {
public:
    typedef long long ll;
    typedef pair<int, ll> P;

    vector<int> cost;
    vector<int> nums;
    vector<P> dp;
    int n;

    ll minIncrease(vector<int>& nums) {
        this->nums = nums;

        n = nums.size();
        cost.resize(n); 
        dp.resize(n); 

        for(int i = 1; i < n-1; i++)
        {
            int m = max(nums[i-1], nums[i+1]);
            if(m < nums[i])
                continue;
            cost[i] = m + 1 - nums[i];
        }

        return solve(1).second;
    }

    P solve(int i)
    {
        if(i >= n - 1)
            return {0,0};

        if(dp[i] != P{0,0})
            return dp[i];

        P skip = solve(i+1);
        P nxt = solve(i+2);
        P take = {1 + nxt.first, cost[i] + nxt.second};

        P res;

        if(skip.first > take.first)
            res = skip;
        else if(take.first > skip.first)
            res = take;
        else 
            res = (skip.second > take.second)? take : skip;

        return dp[i] = res;
    }
};