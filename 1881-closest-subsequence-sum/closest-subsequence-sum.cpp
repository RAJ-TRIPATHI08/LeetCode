class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int mid = n / 2;
        
        auto getSums = [](const vector<int>& arr) {
            vector<int> sums = {0};
            for (int num : arr) {
                int sz = sums.size();
                for (int i = 0; i < sz; ++i) {
                    sums.push_back(sums[i] + num);
                }
            }
            return sums;
        };
        
        vector<int> leftSums = getSums({nums.begin(), nums.begin() + mid});
        vector<int> rightSums = getSums({nums.begin() + mid, nums.end()});
        
        sort(rightSums.begin(), rightSums.end());
        
        int ans = abs(goal);  // empty subsequence
        
        for (int s : leftSums) {
            int target = goal - s;
         
            auto it = lower_bound(rightSums.begin(), rightSums.end(), target);

            if (it != rightSums.end()) {
                ans = min(ans, abs(s + *it - goal));
            }
            
            if (it != rightSums.begin()) {
                ans = min(ans, abs(s + *(it - 1) - goal));
            }
        }
        
        return ans;
    }
};