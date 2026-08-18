class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;

        int n = nums.size();

        for(int i = 0; i <= n-k; i++)
        {
            unordered_set<int> seen;
            for (int j = i; j < i + k; j++) 
                seen.insert(nums[j]);

            for (int val : seen) 
                cnt[val]++;
        }
        
        int res = -1;
        for(auto p : cnt)
            if(p.second == 1)
                res = max(res, p.first);
        return res;
    }
};