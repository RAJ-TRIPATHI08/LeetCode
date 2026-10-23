class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> modulo(n);

        for(int i = 0; i < n; i++)
            modulo[i] = nums[i]%k;

        int res = 1, len = 1;
        for(int i = 1; i < n; i++)
        {
            if(modulo[i-1] == modulo[i])
            {
                len++;
                if(modulo[i] * (len-1) % k == 0)
                    res = max(res, len);
            }
            else
            {
                len = 1;
            }
        }
        return res;
    }
};