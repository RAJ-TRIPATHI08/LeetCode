class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++)
        {
            int num = nums[i];
            if(num == 2)
            {
                ans[i] = -1;
                continue;
            }

            for(int j = 1; j < 32; j++)
            {
                if((num & (1 << j)) > 0)
                {
                    continue;
                }
                int res = (num ^ (1 << (j-1)));
                ans[i] = res;
                break;
            }
        }
        return ans;
    }
};