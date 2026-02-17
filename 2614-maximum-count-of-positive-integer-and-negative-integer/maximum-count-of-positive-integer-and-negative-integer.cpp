class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int negCnt = 0;
        int posCnt = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0) posCnt++;
            else if(nums[i] < 0) negCnt++;
        }
        return max(negCnt, posCnt);
    }
};