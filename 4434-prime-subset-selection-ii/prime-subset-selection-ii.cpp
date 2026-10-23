class Solution {
public:
    vector<int> maxPrimeSubset(int n, int s) {
        vector<bool> primes(n+1, true);
        vector<int> p;
        primes[0] = primes[1] = false;

        for(int i = 2; i <= n; i++)
            if(primes[i])
            {
                for(int j = 2*i; j <= n; j += i)
                    primes[j] = false;
                p.push_back(i);
            }

        int m = p.size();
        int INF = 1e9+7;
        int dp[m+1][s+1];
        fill(&dp[0][0], &dp[0][0] + (m + 1) * (s + 1), INF);

        for(int i = 0; i <= m; i++)
            dp[i][0] = 0;

        for(int i = m-1; i >= 0; i--)
        {
            for(int sum = 0; sum <= s; sum++)
            {
                dp[i][sum] = dp[i+1][sum];

                if(p[i] <= sum && dp[i+1][sum - p[i]] != INF)
                    dp[i][sum] = min(dp[i][sum], 1 + dp[i+1][sum - p[i]]);
                
            }
        }

        int sum = s;
        while(sum > 0 && dp[0][sum] == INF)
            sum--;

        if(sum == 0)
            return {};

        vector<int> res;

        for(int i = 0;  i < m && sum > 0; i++)
            if(p[i] <= sum && dp[i+1][sum - p[i]] != INF && dp[i+1][sum - p[i]] + 1 == dp[i][sum])
            {
                res.push_back(p[i]);
                sum -= p[i];
            }

        return res;
    }
};