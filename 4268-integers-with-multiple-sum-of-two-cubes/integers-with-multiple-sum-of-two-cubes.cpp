class Solution {
public:
    // this is Hardy-Ramanujan good numbers problem
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, int> mp;

        int N = cbrt(n);
        for(int i = 1; i <= N; i++)
        {
            for(int j = i; j <= N; j++)
                {
                    int x = i*i*i + j*j*j;
                    if(x <= n)
                        mp[x]++;
                }
        }

        vector<int> ans;
        for(auto p : mp)
            {
                if(p.second >= 2)
                    ans.push_back(p.first);
            }

        sort(ans.begin(), ans.end());
        return ans;
    }
};