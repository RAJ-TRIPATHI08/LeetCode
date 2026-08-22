class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preSum(n, 0);

        auto check = [&] (int mid) {
            int sum = 0;
            int cnt = 1;

            for(auto n : nums)
            {
                if((n + sum) > mid)
                {
                    cnt++;
                    sum = n;
                }
                else
                {
                    sum += n;
                }
            }
            return cnt <= k;
        };

        int l = *max_element(begin(nums), end(nums));
        int r = accumulate(begin(nums), end(nums), 0);
        int res = r;
        while(l <= r)
        {   
            int mid = l + (r - l)/2;
            if(check(mid))
            {
                r = mid - 1;
                res = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return res;
    }
};