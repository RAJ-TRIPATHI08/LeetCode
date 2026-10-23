class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int INF = INT_MAX;
        int res = INF;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == i)
                continue;

            res &= nums[i];
        }

        return res != INF? res : 0;
    }
};