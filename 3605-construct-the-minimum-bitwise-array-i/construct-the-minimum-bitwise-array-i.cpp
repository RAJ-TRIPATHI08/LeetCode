class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++)
        {
            int num = nums[i];
            for(int j = 0; j < num; j++)
            {
                if((j | j + 1) == num)
                {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};