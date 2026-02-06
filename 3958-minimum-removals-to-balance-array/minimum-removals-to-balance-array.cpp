class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int res = 0;
        for(int j = 0; j < n; j++)
        {
            if(i <= j && nums[j] > (long long)k*nums[i])
                i++;
            else
                res = n - (j-i+1);
        }

        return res;
    }
};