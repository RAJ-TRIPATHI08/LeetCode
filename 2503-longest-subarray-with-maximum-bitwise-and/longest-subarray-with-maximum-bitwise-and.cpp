class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 1;
        int len = 0;
        
        int m = *max_element(nums.begin(), nums.end());

        for(int n : nums)
        {
            if(n == m)
            {
                len++; 
                res = max(res, len);
            }
            else
            {
                res = max(res, len);
                len = 0;
            }
        }
        return res;
    }
};