class Solution {
public:
    vector<int> dp;

    int fibo(int n)
    {
        if(n == 0 || n == 1) return n;
        if(dp[n] != -1) return dp[n];

        return dp[n] = fibo(n-1) + fibo(n-2);
    }
    
    int fib(int n) {
        dp.resize(n+1, -1);
        return fibo(n);
    }
};