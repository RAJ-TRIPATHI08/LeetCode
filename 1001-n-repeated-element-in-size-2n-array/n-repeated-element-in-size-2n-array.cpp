class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        n = n/2;

        unordered_map<int, int> freq;

        for(int v : nums)
        {
            freq[v]++;
            if(freq[v] == n)
                return v;
        }
        return 0;
    }
};