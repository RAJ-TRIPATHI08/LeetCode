class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        auto atMostK = [&](vector<int>& nums, int k) {
            int n = nums.size();
        
            unordered_map<int, int> mp;

            int res = 0;
            int i = 0;
            for(int j = 0; j < n; j++)
            {
                mp[nums[j]]++;

                while(mp.size() > k)
                {
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0)
                        mp.erase(nums[i]);
                    i++;
                }

                res += j - i + 1;
            }
            return res;
        };
        
        int res = atMostK(nums, k) - atMostK(nums, k - 1);
        return res;
    }
};