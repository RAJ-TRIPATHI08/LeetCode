class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int res = 1e9;

        for(int i = 0; i < nums.size()-k+1; i++)
        {
            res = min(res, nums[i+k-1] - nums[i]);
        }
        return res;
    }
};