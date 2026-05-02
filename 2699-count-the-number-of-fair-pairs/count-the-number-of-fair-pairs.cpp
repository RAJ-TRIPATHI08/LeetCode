class Solution {
public:
    typedef long long ll;
    ll countLessEqual(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        ll cnt = 0;

        while (i < j) {
            if ((ll)nums[i] + nums[j] <= target) {
                cnt += (j - i);  
                i++;
            } else {
                j--;
            }
        }
        return cnt;
    }

    ll countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        return countLessEqual(nums, upper) - 
               countLessEqual(nums, lower - 1);
    }
};