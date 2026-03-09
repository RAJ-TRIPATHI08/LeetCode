class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        

        int n = nums.size();
        int res = 0;

        int product = 1;
        int j = 0;

        for(int i = 0; i < n; i++)
        {
            product *= nums[i];
            
            if(product >= k)
            {
                while(j <= i && product >= k)
                    product /= nums[j++];
            }

            res += 1 + i - j;
        }

        return res;
    }
};