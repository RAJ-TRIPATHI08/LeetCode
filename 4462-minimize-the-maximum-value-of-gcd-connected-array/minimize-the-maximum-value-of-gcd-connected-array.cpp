class Solution {
public:
    int spf(int n)
    {
        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0)
                return i;
        }

        return n;
    }

    long long minimumMaxValue(int n, int index, int value) {
        if(value == 1) 
            return -1;

        int p = spf(value);

        if(!(value - p >= 2 * index))
            return -1;

        int t = n - index - 1;

        if(t == 0) 
            return value;

        return 1LL * p + value + 2 * (t - 1);
    }
};