class Solution {
public:
    typedef long long ll;
    ll sumAndMultiply(int n) {
        string N = to_string(n);

        ll x = 0;
        ll sum = 0;
        for(char c : N)
        {
            if(c == '0')
                continue;
            
            int val = c - '0';
            x = x * 10 + val;
            sum += val;
        }

        return x*sum;
    }
};