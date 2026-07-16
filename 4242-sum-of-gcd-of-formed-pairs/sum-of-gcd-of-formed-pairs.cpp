class Solution {
public:
    using ll = long long;

    ll gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        vector<int> prefGcd(n);

        for(int i = 0; i < n; i++)
        {
            mx = max(mx, nums[i]);
            prefGcd[i] = gcd(nums[i], mx);
        }

        int i = 0, j = n-1;
        ll sum = 0;
        sort(begin(prefGcd), end(prefGcd));

        while(i < j)
        {
            int a = prefGcd[i];
            int b = prefGcd[j];

            sum += gcd(a, b);
            i++;
            j--;
        }
        return sum;
    }
};