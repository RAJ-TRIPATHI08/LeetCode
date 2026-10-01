class Solution {
public:
    int N, M, K;
    int dp[51][51][101];
    int MOD = 1e9+7;

    int solve(int idx, int searchCost, int maxElement)
    {
        if(idx == N)
        {
            if(searchCost == K)
                return 1;
            return 0;
        }

        if(dp[idx][searchCost][maxElement] != -1)
            return dp[idx][searchCost][maxElement];

        int res = 0;

        for(int i = 1; i <= M; i++)
        {
            if(i > maxElement)
            {
                res = (res + solve(idx+1, searchCost+1, i)) % MOD;
            }
            else
            {
                res = (res + solve(idx+1, searchCost, maxElement)) % MOD;
            }
        }
        return dp[idx][searchCost][maxElement] = res % MOD;
    }

    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};