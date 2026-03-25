class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<ll> rowSum(n, 0);
        vector<ll> colSum(m, 0);
        ll sum = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
                sum += grid[i][j];
            }
        }

        if(sum%2)
            return false;

        ll top = 0;
        for(int i = 0; i < n-1; i++)
        {
            top += rowSum[i];
            ll bottom = sum - top;

            if(top == bottom)
                return true;
        }

        ll left = 0;
        for(int i = 0; i < m-1; i++)
        {
            left += colSum[i];
            ll right = sum - left;

            if(left == right)
                return true;
        }

        return false;
    }
};