class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0;
        int j = 0;

        int res = INT_MAX;
        int bestLen = INT_MAX;
        int sum = 0;

        vector<int> dp(n, INT_MAX);
        while(j < n)
        {
            sum += arr[j];

            while(sum > target && i <= j)
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

        

        return res != INT_MAX? res : -1;
    }
};