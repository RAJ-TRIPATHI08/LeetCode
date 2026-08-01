class Solution {
public:
    bool solve(int l, int r, int s1, int s2, bool p1, vector<int>& nums)
    {
        if(l > r)
            return s1 >= s2;

        if(p1)        
            return (solve(l+1, r, s1+nums[l], s2, false, nums) || solve(l, r-1, s1+nums[r], s2, false, nums));
        else
            return (solve(l+1, r, s1, s2+nums[l], true, nums) && solve(l, r-1, s1, s2+nums[r], true, nums));
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(0, nums.size()-1, 0, 0, true, nums);
    }
};