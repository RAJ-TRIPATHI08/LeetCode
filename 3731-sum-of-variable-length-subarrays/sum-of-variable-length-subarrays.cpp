class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            int subArrS = max(0, i - nums[i]);
            int subArrE = i;

            for(int j = subArrS; j <= subArrE; j++)
                sum += nums[j];
        }

        return sum;
    }
};