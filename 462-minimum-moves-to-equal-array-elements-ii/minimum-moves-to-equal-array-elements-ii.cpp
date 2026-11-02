class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int mid = nums[n/2];
        int res = 0;

       for(int v : nums)
            res += abs(v - mid);

        return res;
    }
};