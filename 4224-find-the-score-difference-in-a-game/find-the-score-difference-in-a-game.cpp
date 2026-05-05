class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int p1Score = 0;
        int p2Score = 0;

        bool p1 = true;
        bool p2 = false;

        int n = nums.size();
        int round = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] & 1)
            {
                swap(p1, p2);
            }
            
            if(i % 6 == 5)
            {
                swap(p1, p2);
            }

            if(p1)
            {
                p1Score += nums[i];
            }
            else
            {
                p2Score += nums[i];
            }
        }
        return p1Score - p2Score;
    }
};