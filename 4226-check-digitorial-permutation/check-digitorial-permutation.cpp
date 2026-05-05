class Solution {
public:
    typedef long long ll;

    ll fact(ll n)
    {
        if(n <= 1)
            return 1;

        return n * fact(n-1);
    }

    bool isDigitorialPermutation(int n) {
        string num = to_string(n);

        ll factSum = 0;
        vector<ll> preCompute(10, 0);

        for(int i = 0; i < 10; i++)
        {
            preCompute[i] = fact(i);
        }

        for(char c : num)
        {
            factSum += preCompute[c - '0'];
        }

        string factStr = to_string(factSum);

        sort(num.begin(), num.end());
        sort(factStr.begin(), factStr.end());

        return num == factStr;
    }
};