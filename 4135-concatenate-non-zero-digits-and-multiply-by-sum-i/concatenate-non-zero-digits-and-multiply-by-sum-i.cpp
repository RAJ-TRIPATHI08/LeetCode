class Solution {
public:
    using ll = long long;
    ll sumAndMultiply(int n) {
        ll sum = 0;
        ll x = 0;

        string s = to_string(n);

        for(char c : s)
        {
            int d = c - '0';
            if(d != 0)
                x = x*10 + d;
            sum += d;
        }

        return x * sum;
    }
};