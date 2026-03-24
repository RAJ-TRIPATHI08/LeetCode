class Solution {
public:
    int mod = 12345;
    typedef long long ll;

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> p(n, vector<int>(m, 0));

        int size = n*m;

        vector<int> arr;
        for(auto &row : grid)
        {
            for(int x : row)
            {
                arr.push_back(x);
            }
        }

        vector<ll> prefix(size, 1);
        vector<ll> suffix(size, 1);

        for(int i = 1; i < size; i++)
        {
            prefix[i] = (prefix[i-1] * arr[i-1]) % mod;
            cout << prefix[i] << endl;
        }

        for(int i = size - 2; i >= 0; i--)
        {
            suffix[i] = (suffix[i+1] * arr[i+1]) % mod;
            cout << suffix[i] << endl;
        }

        for(int i = 0; i < size; i++)
        {
            p[i/m][i%m] = (prefix[i] * suffix[i])%mod;
        }
        
        return p;
    }
};