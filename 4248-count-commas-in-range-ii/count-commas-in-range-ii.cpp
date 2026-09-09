class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000)
        {
            return 0;
        }

        long long res = 0;

        if (n >= 1000000000000000LL) {
            res += (n - 1000000000000000LL + 1);
        }
        
        if (n >= 1000000000000LL) {
            res += (n - 1000000000000LL + 1);
        }
        
        if (n >= 1000000000LL) {
            res += (n - 1000000000LL + 1);
        }
        
        if (n >= 1000000LL) {
            res += (n - 1000000LL + 1);
        }
        
        if (n >= 1000LL) {
            res += (n - 1000LL + 1);
        }

        return res;
    }
};