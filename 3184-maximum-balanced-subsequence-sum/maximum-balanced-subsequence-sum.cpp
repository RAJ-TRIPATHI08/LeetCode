class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        long long res = *max_element(begin(nums), end(nums));
        map<int, long long> mp;

        for(int i = 0; i < n; i++)
        {
            long long curr_res = nums[i];

            auto it = mp.upper_bound(nums[i] - i);

            if(it != begin(mp)) 
            {
                it--;
                curr_res += it->second;
            }

            mp[nums[i] - i] = max(curr_res, mp[nums[i] - i]);
            it = mp.upper_bound(nums[i] - i);

            while(it != mp.end() && it->second <= curr_res)
                mp.erase(it++);

            res = max(res, curr_res);            
        }
        return res;
    }
};