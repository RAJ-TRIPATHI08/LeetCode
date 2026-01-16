class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        auto getWidth = [&](vector<int> fences) {
            sort(fences.begin(), fences.end());
            int n = fences.size();
        
            unordered_map<int, bool> mp;

            for(int i = 0; i < n; i++)        
            {
                for(int j = i+1; j < n; j++)
                {
                    int width = abs(fences[j] - fences[i]);
                    mp[width] = true;
                }
            }
            return mp;
        };

        unordered_map<int, bool> w = getWidth(vFences); 
        unordered_map<int, bool> h = getWidth(hFences); 

        int resWidth = INT_MIN;
        for(auto i:w) 
        {
            if(h[i.first]) resWidth = max(resWidth, i.first);
        }

        static const int MOD = 1e9 + 7;
        if(resWidth == INT_MIN) return -1;
        return (1LL * resWidth * resWidth) % MOD;
    }
};