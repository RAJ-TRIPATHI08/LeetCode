class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, bool> mp;

        for(int n : nums)
            if(n % k == 0)
                mp[n] = true;

        for(int mul = k; ; mul += k)
            if(!mp[mul])
                return mul;

        return -1;
    }
};