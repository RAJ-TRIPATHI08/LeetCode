class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size();
        int maxProd = INT_MIN;
        vector<int> res;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(nums[i] + nums[j] == target && nums[i] > nums[j] && nums[i] * nums[j] > maxProd)
                {
                    maxProd = nums[i]*nums[j];
                    res.clear();
                    res = {i, j};
                }
            }
        }

        return maxProd == INT_MIN? vector<int>{-1,-1} : res;
    }
};