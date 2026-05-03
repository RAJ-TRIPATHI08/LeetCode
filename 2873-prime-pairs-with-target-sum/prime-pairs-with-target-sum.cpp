class Solution {
public:
    vector<bool> sieve(int n)
    {
        vector<bool> prime(n+1, true);
        prime[0] = prime[1] = false;

        for(int i = 2; i*i <= n; i++)
        {
            if(prime[i])
            {
                for(int j = 2*i; j <= n; j+=i)
                {
                    prime[j] = false;
                }
            }
        }
        return prime;
    }

    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> res;
        vector<bool> isPrime = sieve(n);

        for(int i = 0; i <= n/2; i++)
        {
            if(isPrime[i] && isPrime[n-i])
                res.push_back({i, n-i});
        }
        sort(res.begin(), res.end());
        return res;
    }
};