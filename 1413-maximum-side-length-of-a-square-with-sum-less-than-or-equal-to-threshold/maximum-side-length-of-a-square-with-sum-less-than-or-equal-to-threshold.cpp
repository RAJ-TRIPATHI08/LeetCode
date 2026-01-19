class Solution {
public:
    int maxSideLength(vector<vector<int>>& arr, int threshold) {
        int m = arr.size();     // rows
        int n = arr[0].size();  // cols

        vector<vector<int>> pref(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= m; i++) 
        {
            for(int j = 1; j <= n; j++) 
            {
                pref[i][j] =
                    arr[i-1][j-1]
                + pref[i-1][j]
                + pref[i][j-1]
                - pref[i-1][j-1];
            }
        }

    
        auto findSum = [&](int r1, int c1, int r2, int c2) 
        {
            return pref[r2][c2]
            - pref[r1][c2]
            - pref[r2][c1]
            + pref[r1][c1];
        };

        int bestSide = 0;
        for(int i = 0; i < m; i++) 
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < min(m - i, n - j); k++)  // k is offset
                {
                    int r2 = i + k + 1;
                    int c2 = j + k + 1;

                    int val = findSum(i, j, r2, c2);

                    if(val <= threshold)
                        bestSide = max(k + 1, bestSide);
                    else
                        break;
                }
            }
        }
        return bestSide;
    }
};