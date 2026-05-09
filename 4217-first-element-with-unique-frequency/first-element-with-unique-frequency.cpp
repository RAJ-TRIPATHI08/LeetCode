class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> freqCnt;
        for(int x : nums)
            freq[x]++;

        for(auto p : freq)
            freqCnt[p.second]++;

        for(int x : nums)
        {
            if(freqCnt[freq[x]] == 1)
                return x;
        }
        return -1;
    }
};