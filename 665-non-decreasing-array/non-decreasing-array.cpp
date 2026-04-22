class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int toChng = 0;

        for(int i = 1; i < n; i++)
        {
            if(nums[i-1] > nums[i])
            {
                if(toChng > 0) return false;  // only one change allowed
                toChng++;

                if(i > 1 && nums[i-2] > nums[i])
                    nums[i] = nums[i-1];   // modify current
                else
                    nums[i-1] = nums[i];   // modify previous
            }
        }
        return true;
    }
};