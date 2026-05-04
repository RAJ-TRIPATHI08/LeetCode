class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        vector<int> res;
        vector<pair<int,int>> couldFixed;

        for(int i = 0; i < nums.size(); i++)
        {
            if(i >= nums[i])
                couldFixed.push_back({i - nums[i], nums[i]});
        }

        sort(begin(couldFixed), end(couldFixed));

        for(auto [diff, val] : couldFixed)
        {
            auto it = lower_bound(res.begin(), res.end(), val);

            if(it == res.end())
                res.push_back(val);
            else
                *it = val;
        }

        return res.size();
    }
};