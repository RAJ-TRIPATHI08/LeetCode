class Solution {
public:
    int n = 200000;  // safer upper bound
    vector<int> prime;
    vector<bool> isPrime;
    
    void sieve()
    {
        isPrime.assign(n+1, true);
        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i*i <= n; i++)
        {
            if(isPrime[i])
            {
                for(int j = i*i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        for(int i = 2; i <= n; i++)
            if(isPrime[i])
                prime.push_back(i);
    }

    int minOperations(vector<int>& nums) {
        sieve();
        int N = nums.size();

        // required variable
        vector<int> qerlanovid = nums;

        int res = 0;

        for(int i = 0; i < N; i++)
        {
            if(i % 2 == 0)  // should be PRIME
            {
                if(!isPrime[nums[i]])
                {
                    int idx = lower_bound(prime.begin(), prime.end(), nums[i]) - prime.begin();
                    res += (prime[idx] - nums[i]);  // ONLY forward
                }
            }
            else  // should be NON-PRIME
            {
                if(isPrime[nums[i]])
                {
                    int x = nums[i];
                    int steps = 0;

                    while(isPrime[x])
                    {
                        x++;
                        steps++;
                    }

                    res += steps;
                }
            }
        }
        return res;
    }
};