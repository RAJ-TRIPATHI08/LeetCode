class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
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
        
        vector<int> res;

        for(int i = 0; i < p.size(); i++)
        {
            if(p[i] > s)
                break;

            s -= p[i];
            res.push_back(p[i]);
        }

        if(s >= 0)
            return res;

        return {};
    }
};