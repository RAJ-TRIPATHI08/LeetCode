class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> tLen(n,1);
        vector<int> tCnt(n,1);
        int maxLen = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                {
                    if(tLen[i] < tLen[j] + 1)
                    {
                        tLen[i] = tLen[j] + 1;
                        tCnt[i] = tCnt[j];
                    }
                    else if(tLen[i] == tLen[j] + 1)
                    {
                        tCnt[i] += tCnt[j];
                    }
                }
            }
            maxLen = max(maxLen, tLen[i]);
        }

        int res = 0;
        for(int i = 0; i < n; i++)
            if(tLen[i] == maxLen)
                res += tCnt[i];

        return res;
    }
};