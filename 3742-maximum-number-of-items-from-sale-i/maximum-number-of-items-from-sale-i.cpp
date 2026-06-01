class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> facts(n, 0);

        for (int i = 0; i < n; i++) {
            int f = items[i][0];

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % f == 0)
                    facts[i]++;
            }
        }

        vector<int> dp(budget + 1, -1e9);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int p = items[i][1];

            for(int c = budget; c >= p; c--)
                dp[c] = max(dp[c], dp[c-p] + facts[i] + 1);      

            for(int c = p; c <= budget; c++)
                if(dp[c-p] != -1e9)
                    dp[c] = max(dp[c], dp[c-p] + 1);      
        }

        return *max_element(dp.begin(), dp.end());
    }
};