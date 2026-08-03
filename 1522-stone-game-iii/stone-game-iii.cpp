class Solution {
public:
    vector<int> dp;
    int solve(int i, int n, vector<int>& A)
    {
        if(i == n)
            return 0;
            
        if(dp[i] != INT_MIN)
            return dp[i];

        int res = A[i] - solve(i+1, n, A);

        if(i+2 <= n)
            res = max(res, A[i] + A[i+1] - solve(i+2, n, A));
        if(i+3 <= n)
            res = max(res, A[i] + A[i+1] + A[i+2] - solve(i+3, n, A));

        return dp[i] = res;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        dp.resize(stoneValue.size() + 1, INT_MIN);
        int score = solve(0, stoneValue.size(), stoneValue);

        return (score > 0)? "Alice" :(score == 0? "Tie" : "Bob"); 
    }
};