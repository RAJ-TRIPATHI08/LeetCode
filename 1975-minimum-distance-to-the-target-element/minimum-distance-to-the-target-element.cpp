class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();

        auto search = [&]() {
            int res = INT_MAX;
            for(int i = 0; i < n; i++)
                if(nums[i] == target)
                    res = min(res, abs(i-start));
            
            return res;
        };

        return search();
    }
};