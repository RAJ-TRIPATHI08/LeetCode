class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0;
        int j = 0;

        int minLen = INT_MAX, minLen1 = INT_MAX;
        int res = INT_MAX;
        int bestLen = INT_MAX;
        int sum = 0;
        vector<int> dp(n, INT_MAX);
        while(j < n)
        {
            sum += arr[j];

            while(sum > target && i < j)
            {
                sum -= arr[i];
                i++;
            }

            if(sum == target)
            {
                if(i > 0 && dp[i-1] != INT_MAX)
                {
                    res = min(res, j-i+1 + dp[i-1]);
                }
                bestLen = min(bestLen, j-i+1);
            }

            dp[j] = bestLen;
            j++;
        }

        if(res == INT_MAX)
            return -1;

        return res;
    }
};