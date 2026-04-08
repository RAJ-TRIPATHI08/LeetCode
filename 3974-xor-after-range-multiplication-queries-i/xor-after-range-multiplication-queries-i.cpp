class Solution {
public:
    typedef long long ll;
    int mod = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size();

        for(int i = 0; i < q; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            int idx = l;

            while(idx <= r)
            {
                ll n = nums[idx];
                n *= v;

                if(n >= mod)
                    n %= mod;

                nums[idx] = n;
                idx += k; 
            }
        }

        int res = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            res ^= nums[i];
        }
        return res;
    }
};