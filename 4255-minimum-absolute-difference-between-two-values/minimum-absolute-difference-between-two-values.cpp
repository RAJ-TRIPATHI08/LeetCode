class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int one = -1, two = -1;
        int res = INT_MAX;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
                one = i;
            if(nums[i] == 2)
                two = i;

            if(one != -1 && two != -1)
                res = min(res, abs(two - one));
        }

        return res == INT_MAX? -1 : res;
    }
};