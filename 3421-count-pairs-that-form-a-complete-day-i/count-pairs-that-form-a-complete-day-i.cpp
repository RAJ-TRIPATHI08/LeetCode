class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> mp; // {rem, freq};
        int res = 0;

        for(int hr : hours)
        {
            int rem = hr % 24;
            if(rem == 0)
            {
                res += mp[rem];
            }
            else
            {
                res += mp[24-rem];
            }
            mp[rem]++;
        }

        return res;
    }
};