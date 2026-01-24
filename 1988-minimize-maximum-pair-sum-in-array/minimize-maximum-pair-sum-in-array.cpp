class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        int res = -1e9;
        sort(nums.begin(), nums.end());

        while(i < j) 
        {
            res = max(res, nums[i++] + nums[j--]);
        }
        return res;
    }
};