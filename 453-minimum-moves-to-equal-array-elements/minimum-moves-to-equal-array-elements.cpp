class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = *min_element(begin(nums), end(nums));

        int res = 0;
        for(int x : nums)
            res += x - min;

        return res;
    }
};