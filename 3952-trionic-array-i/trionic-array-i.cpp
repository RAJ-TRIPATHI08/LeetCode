class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        int i;
        // for increasing part
        for(i = 0; i < n - 1; i++)
        {
            if(nums[i] < nums[i+1])
            {
                continue;
            }
            else
            {
                break;
            }
        }

        // if increasing part is not there or there is only increasing part
        // return false
        if(i == 0 || i == n - 1) return false;

        // for dec. part onwards
        int j = i;
        for(j; j < n - 1; j++)
        {
            if(nums[j] > nums[j+1])
            {
                continue;
            }
            else
            {
                break;
            }
        }

        // means there only exist dec part or no dec part there 
        if(j == 1 || j == n - 1) return false;

        // 
        int k = j;
        for(k; k < n - 1; k++)
        {
            if(nums[k] < nums[k+1])
            {
                continue;
            }
            else
            {
                break;
            }
        }

        // if there is no second inc part or there is not fully inc part
        if(k == j || k != n - 1) return false;

        return true;
    }
};