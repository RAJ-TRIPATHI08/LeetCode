class Solution {
public:
    typedef long long ll;
    ll countPairs(vector<int>& nums, int k) {
        ll res = 0;
        int n = nums.size();
        unordered_map<int, int> mp; // gcd->freq

        for(int i = 0; i < n; i++)
        {
            int g = gcd(nums[i], k);

            for(auto [g2, cnt] : mp)
            {
                if((ll) g*g2%k == 0)
                    res += cnt;
            }
            mp[g]++;
        }

        return res;
    }
};