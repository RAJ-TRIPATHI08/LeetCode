class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> vec;
        for(int n:arr)
        {
            int setBits = __builtin_popcount(n);
            vec.push_back({n, setBits});
        }

        sort(vec.begin(), vec.end(), [](pair<int,int> &a, pair<int,int> &b) {
            if (a.second == b.second)
                return a.first < b.first;   // tie → sort by first
            return a.second < b.second;     // sort by second
        });


        vector<int> res;
        for(auto p:vec) res.push_back(p.first);

        return res;
    }
};