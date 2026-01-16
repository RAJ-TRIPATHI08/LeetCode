class Solution {
public:
    double myPow(double x, int n) {

        auto power = [&](auto&& self, double x, long long n) -> double {
            if (n == 0) return 1.0;

            double half = self(self, x, n / 2);

            if (n % 2 == 0)
                return half * half;
            else
                return half * half * x;
        };

        long long exp = llabs((long long)n);
        double res = power(power, x, exp);

        if (n < 0) res = 1.0 / res;
        return res;
    }
};
