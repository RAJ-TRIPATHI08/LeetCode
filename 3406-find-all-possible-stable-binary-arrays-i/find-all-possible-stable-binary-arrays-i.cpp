class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1001][1001][2];

    int solve(int one, int zero, bool lastWasOne, int limit)
    {
        if(one == 0 && zero == 0)
            return 1;

        if(dp[one][zero][lastWasOne] != -1)
            return dp[one][zero][lastWasOne];

        long long res = 0;

        if(lastWasOne)
        {
            // go with zero's streak
            for(int len = 1; len <= min(zero, limit); len++)
            {
                res = (res + solve(one, zero - len, false, limit)) % mod;
            }
        }
        else
        {
            // last was zero, continue with one's streak
            for(int len = 1; len <= min(one, limit); len++)
            {
                res = (res + solve(one - len, zero, true, limit)) % mod;
            }
        }

        return dp[one][zero][lastWasOne] = res;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));

        int startWithOne = solve(one, zero, true, limit);
        int startWithZero = solve(one, zero, false, limit);

        return (startWithOne + startWithZero) % mod;
    }
};