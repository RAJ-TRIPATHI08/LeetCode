class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int front = 0;
        int mxFront = 0;
        int mnFront = 0;
        int mx = *max_element(begin(nums), end(nums));
        int mn = *min_element(begin(nums), end(nums));
        
        for(int x : nums)
        {
            mxFront++;
            if(x == mx)
                break;
        }

        for(int x : nums)
        {   
            mnFront++;
            if(x == mn)
                break;
        }
        
        front = max(mxFront, mnFront);
        
        int n = nums.size();
        
        int back = 0;
        int mxBack = 0;
        int mnBack = 0;
        for(int i = n - 1; i >= 0; i--)
        {   
            mxBack++;
            if(nums[i] == mx)
                break;
        }

        for(int i = n - 1; i >= 0; i--)
        {
            mnBack++;
            if(nums[i] == mn)
                break;
        }
        back = max(mxBack, mnBack);

        int bothEnd = min(mxFront + mnBack, mxBack + mnFront);

        return min({bothEnd, front, back});
    }
};