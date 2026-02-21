class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int res = 0;

        auto isPrime = [&](int n) {
            if(n <= 1) return false;
            for(int i = 2; i <= n/2; i++)
            {
                if(n%i == 0) return false;
            }
            return true;
        };

        for(int i = left; i <= right; i++)
        {
            int cnt = __builtin_popcount(i);
            // if(isPrime(cnt)) res++;
            if((1 << cnt) & 665772)  // 665772 has prime bits set
                res++;
        }
        return res;
    }
};