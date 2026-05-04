class Solution {
public:
    typedef long long ll;
    int rev(int n) {
        int reverse = 0;
        while(n > 0) {
            int digit = n % 10;
            if(digit != 0) reverse = reverse * 10 + digit;
            n = n / 10;
        }
        return reverse;
    }

    int rev1(int n) {
        int reverse = 0;
        while(n > 0) {
            int digit = n % 10;
            reverse = reverse * 10 + digit;
            n = n / 10;
        }
        return reverse;
    }

    ll sum(int n) {
        ll ans = 0;
        while(n > 0) {
            ans += n % 10;
            n = n / 10;
        }
        return ans;
    }
    
    long long sumAndMultiply(int n) {
        ll num = rev(n);
        num = rev1(num);
        ll ans = num * sum(num);
        return ans;
    }
};